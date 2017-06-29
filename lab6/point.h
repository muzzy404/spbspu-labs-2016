#ifndef POINT_H
#define POINT_H

#include <ostream>

struct Point
{
  int x, y;
};

Point makePoint(int x, int y);

std::ostream & operator<<(std::ostream &, const Point &);

#endif // POINT_H
