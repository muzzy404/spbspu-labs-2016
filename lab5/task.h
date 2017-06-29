#ifndef TASK_LAB5
#define TASK_LAB5

#include "data_struct.h"

//#include <iostream>

struct DataLess
{
  bool operator()(const DataStruct &left, const DataStruct &right) const
  {
    if (left.key1 != right.key1)
    {
      return (left.key1 < right.key1);
    }
    if (left.key2 != right.key2)
    {
      return (left.key2 < right.key2);
    }
    return (left.str.size() < right.str.size());
  };
};

std::ostream & operator<<(std::ostream &, const DataStruct &);
std::istream & operator>>(std::istream &, DataStruct &);

void makeTask();

#endif // TASK_LAB5
