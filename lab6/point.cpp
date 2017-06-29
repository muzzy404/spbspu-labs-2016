#include "point.h"

#include <ostream>

Point makePoint(int x, int y) // like make pair
{
  Point p{ x, y };
  return p;
}

std::ostream & operator<<(std::ostream & os, const Point & point)
{
  os << "(" << point.x << ";" << point.y << ")";
  return os;
}
