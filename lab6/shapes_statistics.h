#ifndef SHAPES_STATISTICS_H
#define SHAPES_STATISTICS_H

#include "shapes.h"

ShapeType determineShapeType(const Shape &);

struct LessShape
{
  bool operator()(const Shape & a, const Shape & b)
  {
    return (determineShapeType(a) < determineShapeType(b));
  }
};

void shapesStatistics(const Shapes &);

#endif // SHAPES_STATISTICS_H
