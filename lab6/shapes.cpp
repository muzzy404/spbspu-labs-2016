#include "shapes.h"

#include <iostream>
#include <sstream>
//#include <string>    // if <ssteram> included, is it necessary to include <string>?
#include <iterator>
#include <algorithm>
#include <cctype>      // isspace


std::ostream & operator<<(std::ostream & os, const Shape & item)
{
  os << item.size() << " ";
  std::copy(item.begin(), item.end(), std::ostream_iterator<Point> (os, " "));
  return os;
}

std::istream & operator>>(std::istream & is, Shape & item)
{
  item.clear();

  std::istream::sentry s(is);
  if(!s)
  {
    return is;
  }

  std::string line;
  std::getline(is, line, '\n');

  line.erase(std::remove_if(line.begin(),
                            line.end(),
                            [](char x){ return std::isspace(x); }),
             line.end());
  std::istringstream stream(line);

  int vertices = 0;
  stream >> vertices;
  if (vertices < 3)
  {
    is.setstate(std::istream::failbit);
    std::cerr << "invalid number of vertices \"" << vertices << "\"\n";
    return is;
  }

  for (int i = 0; i < vertices; ++i)
  {
    char paren1    = '.',
         paren2    = '.',
         semicolon = '.';
    int x, y;

    stream >> paren1 >> x >> semicolon >> y >> paren2;

    if ((paren1 != '(') || (semicolon != ';') || (paren2 != ')'))
    {
      is.setstate(std::istream::failbit);
      std::cerr << "invalid format of data\n";
      return is;
    }

    item.push_back(makePoint(x, y));
  }

  std::string rest;
  stream >> rest;

  if (!rest.empty())
  {
    is.setstate(std::istream::failbit);
    std::cerr << "extra data\n";
  }

  return is;
}
