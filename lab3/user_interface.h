#ifndef USER_INTERFACE
#define USER_INTERFACE

#include "priority_queue_lab.h"

#include <string>
#include <functional>
#include <map>
#include <utility>     // std::pair

class UserInterface
{
public:
  typedef PriorityQueue<std::string> PriorityQueueStr;
  static void executeCommand(PriorityQueueStr &);

private:
  typedef enum
  {
    ADD,
    GET,
    ACCELERATE,
    PRINT,
    NONE,
  } Command;

  typedef std::pair<PriorityQueueStr::ElementPriority, std::string> Data;

  static Command command_;
  static Data    data_;

  static void readCommand();

  static void addElement(PriorityQueueStr &);
  static void getElement(PriorityQueueStr &);
  static void accelerate(PriorityQueueStr &);
  static void printQueue(const PriorityQueueStr &);

  typedef std::function<void(PriorityQueueStr &)> Operation;
  typedef std::map<Command, Operation>            QueueFunctionality;
  static QueueFunctionality functionality_;

  typedef std::map<const std::string, PriorityQueueStr::ElementPriority> QueuePriority;
  static QueuePriority priority_;
};

#endif // USER_INTERFACE
