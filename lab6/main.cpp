#include "tasks.h"

#include <iostream>
#include <exception>

int main(int argc, char * argv[])
{
  if (argc != 2)
  {
    std::cerr << "missing argument\n";
    return 1;
  }

  try
  {
    switch (std::stoi(argv[1]))
    {
      case 1:
        makeTask1();
        break;
      case 2:
        makeTask2();
        break;
      default:
        std::cerr << "no task \"" << argv[1] << "\"\n";
        return 1;
    }
  }
  catch(std::exception & e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }

  return 0;
}
