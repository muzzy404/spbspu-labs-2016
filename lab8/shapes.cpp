#include "shape_types.h"
#include "shapes.h"

#include <sstream>
#include <iostream>
#include <algorithm>  // spaces removing
#include <cctype>     // isspace

bool Shape::isMoreLeft(const Shape & sh) const
{
  return (x_ < sh.x_);
}

bool Shape::isUpper(const Shape & sh) const
{
  return (y_ > sh.y_);
}

/* --- drawing --- */
void Circle::draw() const
{
  std::cout << "CIRCLE ("   << x_ << ";" << y_ << ")\n";
}

void Triangle::draw() const
{
  std::cout << "TRIANGLE (" << x_ << ";" << y_ << ")\n";
}

void Square::draw() const
{
  std::cout << "SQUARE ("   << x_ << ";" << y_ << ")\n";
}
/*--------------------------------------------------------*/

std::istream & operator>>(std::istream & is, std::shared_ptr<Shape> & shapes)
{
  std::istream::sentry s(is);
  if(!s)
  {
    return is;
  }

  std::string line;
  std::getline(is, line, '\n');
  std::istringstream stream(line);

  std::string shape;
  std::getline(stream, shape, '(');
  shape.erase(std::remove_if(shape.begin(),
                             shape.end(),
                             [](char x){ return std::isspace(x); }),
              shape.end());
  //std::cout << "|" << shape << "|\n";

  char paren     = '.';
  char semicolon = '.';
  int x, y;

  stream >> x >> semicolon >> y >> paren;

  if ((semicolon != ';') || (paren != ')'))
  {
    is.setstate(std::istream::failbit);
    std::cerr << "invalid data format\n";
    return is;
  }

  ShapeTypes::Type type = ShapeTypes::determineType(shape);

  switch (type)
  {
    case ShapeTypes::CIRCLE:
    {
      std::shared_ptr<Circle> newCircle(new Circle(x, y));
      shapes = newCircle;
      break;
    }
    case ShapeTypes::TRIANGLE:
    {
      std::shared_ptr<Triangle> newTriangle(new Triangle(x, y));
      shapes = newTriangle;
      break;
    }
    case ShapeTypes::SQUARE:
    {
      std::shared_ptr<Square> newSquare(new Square(x, y));
      shapes = newSquare;
      break;
    }
    case ShapeTypes::UNKNOWN:
    {
      is.setstate(std::istream::failbit);
      std::cerr << "unknown shape type\n";
      return is;
    }
  }

  return is;
}
