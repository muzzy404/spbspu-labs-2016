#include "tasks.h"

#include <iostream>
#include <string>     // std::stoi
#include <exception>  // std::exception

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "wrong number of arguments\n";
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
        makeTask2(20, 1, 20);
        break;
      default:
        std::cerr << "invalid task number: " << argv[1] << "\n";
        return 1;
    }
  }
  catch(const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  return 0;
}
