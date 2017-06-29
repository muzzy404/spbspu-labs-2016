#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

#include <vector>
#include <list>

typedef enum
{
  TRIANGLE,
  SQUARE,
  RECTANGLE,
  UNKNOWN,
} ShapeType;

typedef std::vector<Point> Shape;
typedef std::list<Shape> Shapes;

std::ostream & operator<<(std::ostream &, const Shape &);
std::istream & operator>>(std::istream &, Shape &);

#endif // SHAPE_H
