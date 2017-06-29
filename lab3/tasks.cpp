#include "tasks.h"
#include "user_interface.h"

#include <iostream>
#include <iterator>
#include <stdexcept>

void makeTask1()
{
  UserInterface::PriorityQueueStr queue;

  while(!std::cin.eof())
  {
    UserInterface::executeCommand(queue);
  }
}

void makeTask2(const unsigned int maxSize, int minVal, int maxVal)
{
  std::list<int> ints;
  // task 1 - input
  while(true)
  {
    int elem;
    std::cin >> elem;
    // input errors
    if (std::cin.fail())
    {
      if (std::cin.eof())
      {
        break;
      }
      throw std::ios_base::failure("invalid type of input");
    }
    if ((elem < minVal) || (elem > maxVal) || (ints.size() == maxSize))
    {
      throw std::invalid_argument("input error");
    }

    ints.push_back(elem);
  }
  // task 2 - print to center
  auto frw = ints.begin();
  auto bkw = ints.rbegin();

  for(; frw != bkw.base();)
  {
    std::cout << *frw++ << ' ';
    if (frw == bkw.base())
    {
      break;
    }
    std::cout << *bkw++ << ' ';
  }
  std::cout << '\n';
}
