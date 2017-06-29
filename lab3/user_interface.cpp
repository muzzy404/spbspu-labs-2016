#include "user_interface.h"

#include <iostream>
#include <sstream>   // std::istringstream
#include <stdexcept> // std::invalid_argument

UserInterface::QueueFunctionality UserInterface::functionality_
                                  ({{ ADD,        Operation(addElement) },
                                    { GET,        Operation(getElement) },
                                    { ACCELERATE, Operation(accelerate) },
                                    { PRINT,      Operation(printQueue) },});

UserInterface::QueuePriority UserInterface::priority_
                             ({{ "low",    PriorityQueueStr::LOW    },
                               { "normal", PriorityQueueStr::NORMAL },
                               { "high",   PriorityQueueStr::HIGH   },});

UserInterface::Command UserInterface::command_ = NONE;
UserInterface::Data    UserInterface::data_    = std::make_pair(PriorityQueueStr::LOW, "<EMPTY>");


void UserInterface::readCommand()
{
  command_ = NONE;
  std::string line;
  std::getline(std::cin >> std::ws, line, '\n');

  if (line == "get")
  {
    command_ = GET;
    return;
  }
  if (line == "accelerate")
  {
    command_ = ACCELERATE;
    return;
  }
  if (line == "print")
  {
    command_ = PRINT;
    return;
  }

  std::istringstream stream(line);
  std::string str;
  stream >> str;

  if (str == "add")
  {
    std::string priority;
    stream >> priority;

    str.clear();
    std::getline(stream >> std::ws, str);
    if (str.empty())
    {
      throw std::invalid_argument("missing string");
    }

    data_ = std::make_pair(priority_.at(priority), str);
    command_ = ADD;
    return;
  }

  throw std::invalid_argument("command is not supported");
}

void UserInterface::executeCommand(PriorityQueueStr & queue)
{
  try
  {
    readCommand();
    functionality_.at(command_)(queue);
  }
  catch(const std::exception & e)
  {
    //std::cerr << e.what() << "\n";
    if (!std::cin.eof())
    {
      std::cout << "<INVALID COMMAND>\n";
    }
  }
}

void UserInterface::addElement(PriorityQueueStr & q)
{
  // first - priority, second - element
  q.putElement(data_.second, data_.first);
}

void UserInterface::getElement(PriorityQueueStr & q)
{
  try
  {
    std::cout << *q.getElement() << "\n";
  }
  catch(const std::exception & e)
  {
    std::cout << e.what() << "\n";
  }
}

void UserInterface::accelerate(PriorityQueueStr & q)
{
  q.accelerate();
}

void UserInterface::printQueue(const PriorityQueueStr & q)
{
  q.printQueue();
}
