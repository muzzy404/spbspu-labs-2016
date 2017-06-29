#include "shapes.h"
#include "shapes_statistics.h"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <set>

void makeTask1()
{
  std::set<std::string> words;
  // reading
  std::copy(std::istream_iterator<std::string>(std::cin),
            std::istream_iterator<std::string>(),
            std::inserter(words, words.end()));

  std::copy(words.begin(), words.end(),
            std::ostream_iterator<std::string> (std::cout, "\n"));
}

void makeTask2()
{
  //task 1 - shapes reading
  Shapes shapes(std::istream_iterator<Shape>(std::cin),
                std::istream_iterator<Shape>());
  if (!std::cin.eof())
  {
    throw std::runtime_error("error of reading");
  }

  // task 2 and 3 statistics
  shapesStatistics(shapes);

  // task 4 - pentagons removing
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
               [](const Shape & item){ return (item.size() == 5); }),
               shapes.end());

  // task 5 vector
  std::vector<Point> points;
  std::transform(shapes.begin(), shapes.end(),
                 std::back_insert_iterator<std::vector<Point>>(points),
                 [](const Shape & item){ return item[0]; });
  std::cout << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator<Point> (std::cout, " "));
  std::cout << "\n";

  // task 6 - sorting
  shapes.sort(LessShape());
  std::cout << "Shapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape> (std::cout, "\n"));
}
