#include "tasks.h"

#include <iostream>
#include <exception>

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "invalid number of arguments\n";
    return 1;
  }

  try
  {
    int task = std::stoi(argv[1]);
    switch (task)
    {
      case 1:
        makeTask1();
        break;
      case 2:
        makeTask2();
        break;
      default:
        std::cerr << "invalid task number: " << task << "\n";
        return 1;
    }
  }
  catch(std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  return 0;
}
