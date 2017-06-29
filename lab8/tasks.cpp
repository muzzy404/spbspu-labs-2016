#include "tasks.h"

#include "shapes.h"

#include <iostream>
#include <cmath>      // acos()
#include <algorithm>
#include <iterator>
#include <list>

void makeTask1()
{
  const double PI = std::acos(-1);
  std::transform(std::istream_iterator<double>(std::cin),
                 std::istream_iterator<double>(),
                 std::ostream_iterator<double>(std::cout, " "),
                 std::bind1st(std::multiplies<double>(), PI));
                 /*[PI](double num){ return (PI * num); });*/
  if (!std::cin.eof())
  {
    throw std::ios_base::failure("wrong data format");
  }
  std::cout << "\n";
}

void makeTask2()
{
  typedef std::shared_ptr<Shape>       ShapePtr;
  typedef std::shared_ptr<const Shape> ShapePtrConst;

  std::list<ShapePtr> shapes(std::istream_iterator<ShapePtr>(std::cin),
                             std::istream_iterator<ShapePtr>());
  if (!std::cin.eof())
  {
    throw std::ios_base::failure("input error");
  }

  /* --- Original --- */
  std::cout << "Original:\n";
  std::for_each(shapes.begin(), shapes.end(),
                [](const ShapePtrConst & sPtr){ sPtr->draw(); });

  /* --- Left-Right --- */
  std::cout << "Left-Right:\n";
  shapes.sort([](const ShapePtrConst & left,
                 const ShapePtrConst & right)
                 {
                   return  left->isMoreLeft(*(right.get())); // using * to get an object
                 });
  std::for_each(shapes.begin(), shapes.end(),
                [](const ShapePtrConst & sPtr){ sPtr->draw(); });

  /* --- Right-Left --- */
  std::cout << "Right-Left:\n";
  shapes.sort([](const ShapePtrConst & left,
                 const ShapePtrConst & right)
                 {
                   return  right->isMoreLeft(*(left.get()));
                 });
  std::for_each(shapes.begin(), shapes.end(),
                [](const ShapePtrConst & sPtr){ sPtr->draw(); });

  /* --- Top-Bottom --- */
  std::cout << "Top-Bottom:\n";
  shapes.sort([](const ShapePtrConst & left,
                 const ShapePtrConst & right)
                 {
                   return  left->isUpper(*(right.get()));
                 });
  std::for_each(shapes.begin(), shapes.end(),
                [](const ShapePtrConst & sPtr){ sPtr->draw(); });

  /* --- Bottom-Top --- */
  std::cout << "Bottom-Top:\n";
  shapes.sort([](const ShapePtrConst & left,
                 const ShapePtrConst & right)
                 {
                   return  right->isUpper(*(left.get()));
                 });
  std::for_each(shapes.begin(), shapes.end(),
                [](const ShapePtrConst & sPtr){ sPtr->draw(); });
}
