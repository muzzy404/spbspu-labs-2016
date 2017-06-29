#include "shapes.h"
#include "shapes_statistics.h"

#include <iostream>

ShapeType determineShapeType(const Shape & shape)
{
  ShapeType type = UNKNOWN;
  switch (shape.size())
  {
    case 3:
    {
      type = TRIANGLE;
      break;
    }
    case 4:
    {
      std::size_t side1    = (shape[0].x - shape[1].x)*(shape[0].x - shape[1].x) + //       4_ _ _ _ 3
                             (shape[0].y - shape[1].y)*(shape[0].y - shape[1].y);  // 1-2   |        |
      std::size_t side2    = (shape[0].x - shape[3].x)*(shape[0].x - shape[3].x) + //       |        |
                             (shape[0].y - shape[3].y)*(shape[0].y - shape[3].y);  // 1-4   |        |
      std::size_t diagonal = (shape[0].x - shape[2].x)*(shape[0].x - shape[2].x) + //       |_ _ _ _ |
                             (shape[0].y - shape[2].y)*(shape[0].y - shape[2].y);  // 1-3   1        2
      if ( (side1 + side2) == diagonal ) // Pythagorean theorem
      {
        if (side1 == side2)
        {
          type = SQUARE;
          break;
        }
        type = RECTANGLE;
      }
      break;
    }
  }

  return type;
}

void shapesStatistics(const Shapes & shapes)
{
  std::size_t vertices   = 0;
  std::size_t triangles  = 0;
  std::size_t squares    = 0;
  std::size_t rectangles = 0;

  for(const Shape & item : shapes)
  {
    vertices += item.size();

    switch (determineShapeType(item))
    {
      case UNKNOWN:
      {
        continue;
      }
      case TRIANGLE:
      {
        triangles++;
        break;
      }
      case SQUARE:
      {
        squares++;
        rectangles++;
        break;
      }
      case RECTANGLE:
      {
        rectangles++;
        break;
      }
    }

  }
  // print statistics results
  std::cout << "Vertices: "   << vertices   << "\n";
  std::cout << "Triangles: "  << triangles  << "\n";
  std::cout << "Squares: "    << squares    << "\n";
  std::cout << "Rectangles: " << rectangles << "\n";
}
