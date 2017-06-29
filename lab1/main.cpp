#include "tasks.h"

#include <iostream>
#include <string>     // std::stoi
#include <exception>

int main(int argc, char * argv[])
{
  if (argc < 2)
  {
    std::cerr << "no task selection\n";
    return 1;
  }

  try
  {
    switch (std::stoi(argv[1]))
    {
      case 1:
        makeTask1(argc, argv);
        break;
      case 2:
        makeTask2(argc, argv);
        break;
      case 3:
        makeTask3(argc);
        break;
      case 4:
        makeTask4(argc, argv);
        break;
      default:
        std::cerr << "no task number " << argv[1] << "\n";
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
