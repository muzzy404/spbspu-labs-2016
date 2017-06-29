#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <list>
#include <memory>       // std::shared_ptr
#include <algorithm>    // std::copy
#include <iterator>     // std::ostream_iterator
#include <iostream>     // to print queue
#include <stdexcept>    // std::logic_error

template <class T>
class PriorityQueue
{
public:
  typedef enum
  {
    LOW,
    NORMAL,
    HIGH,
  } ElementPriority;

  void putElement(const T &, const ElementPriority);
  const std::shared_ptr<T> getElement();

  void printQueue() const;
  void accelerate();

private:
  typedef std::list<T> Queue;
  Queue low_;
  Queue normal_;
  Queue high_;
};

template <class T>
void PriorityQueue<T>::putElement(const T & elem, const ElementPriority priority)
{
  switch (priority)
  {
    case HIGH:
      high_.push_back(elem);
      break;
    case NORMAL:
      normal_.push_back(elem);
      break;
    case LOW:
      low_.push_back(elem);
      break;
  }
}

template <class T>
const std::shared_ptr<T> PriorityQueue<T>::getElement()
{
  std::shared_ptr<T> elem;

  if (!high_.empty())
  {
    elem = std::make_shared<T>(high_.front());
    high_.pop_front();
  }
  else if (!normal_.empty())
  {
    elem = std::make_shared<T>(normal_.front());
    normal_.pop_front();
  }
  else if (!low_.empty())
  {
    elem = std::make_shared<T>(low_.front());
    low_.pop_front();
  }
  else // every part of queue is empty
  {
    throw std::logic_error("<EMPTY>");
  }

  return elem;
}

template <typename T>
void PriorityQueue<T>::printQueue() const
{
  std::copy(high_.begin(), high_.end(),
            std::ostream_iterator<T>(std::cout, "\n"));
  std::copy(normal_.begin(), normal_.end(),
            std::ostream_iterator<T>(std::cout, "\n"));
  std::copy(low_.begin(), low_.end(),
            std::ostream_iterator<T>(std::cout, "\n"));
}

template <typename T>
void PriorityQueue<T>::accelerate()
{
  high_.splice(high_.end(), low_);
}

#endif // PRIORITY_QUEUE
