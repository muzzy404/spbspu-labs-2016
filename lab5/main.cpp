#include "task.h"

#include <stdexcept>
#include <iostream>

int main()
{
  try
  {
    makeTask();
  }
  catch(std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
