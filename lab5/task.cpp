#include "task.h"
#include "data_struct.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iterator>

std::ostream & operator<<(std::ostream & os, const DataStruct & data)
{
  os << data.key1 << "," << data.key2 << "," << data.str;
  return os;
};

std::istream & operator>>(std::istream & is, DataStruct & data)
{
  std::istream::sentry s(is);
  if(!s)
  {
    return is;
  }

  char comma;
  int key1, key2;
  is >> key1 >> comma;

  if (comma != ',')
  {
    is.setstate(std::istream::failbit);
    std::cerr << "invalid separator 1\n";
    return is;
  }
  is >> key2 >> comma;
  if (comma != ',')
  {
    is.setstate(std::istream::failbit);
    std::cerr << "invalid separator 2\n";
    return is;
  }

  if ((std::abs(key1) > KEY_LIMIT) || (std::abs(key2) > KEY_LIMIT))
  {
    is.setstate(std::istream::failbit);
    std::cerr << "key1 or key2 out of range\n";
    return is;
  }

  std::string str;
  std::getline(is >> std::ws, str, '\n');
  if (str.empty())
  {
    is.setstate(std::istream::failbit);
    throw std::ios_base::failure("missing string");
  }

  data.key1 = key1;
  data.key2 = key2;
  data.str  = str;

  return is;
}

void makeTask()
{
  //std::vector<DataStruct> vector;
  try
  {
    /*std::copy(std::istream_iterator<DataStruct>(std::cin),
              std::istream_iterator<DataStruct>(),
              std::back_inserter(vector));*/
    std::vector<DataStruct> vector((std::istream_iterator<DataStruct>(std::cin)),
                                    std::istream_iterator<DataStruct>());
    if (!std::cin.eof())
    {
      throw std::ios_base::failure("input error");
    }
    std::sort(vector.begin(), vector.end(), DataLess());
    std::copy(vector.begin(), vector.end(),
              std::ostream_iterator<DataStruct>(std::cout, "\n"));
  }
  catch(std::exception & e)
  {
    //vector.clear();
    throw std::ios_base::failure(e.what());
  }
}
