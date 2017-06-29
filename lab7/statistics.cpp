#include "statistics.h"

#include <stdexcept>

Statistics::Statistics():
  max_(0),   min_(0),
  first_(0), last_(0),

  positiveNum_(0),
  negativeNum_(0),
  elementsNum_(0),

  oddsSum_(0),
  evensSum_(0),
  sum_(0)
{}

void Statistics::operator()(int num)
{
  // first number
  if (!elementsNum_)
  {
    max_   = num;
    min_   = num;
    first_ = num;
  }

  // max and min
  if (num > max_)
  {
    max_ = num;
  }
  else if (num < min_)
  {
    min_ = num;
  }

  // amounts
  if (num > 0)
  {
    ++positiveNum_;
  }
  else if (num < 0)
  {
    ++negativeNum_;
  }

  // sums
  if ((num % 2) == 0)
  {
    evensSum_ += num;
  }
  else
  {
    oddsSum_ += num;
  }
  sum_ += num;

  last_ = num;
  ++elementsNum_;
}

// getters
int Statistics::max() const
{
  return max_;
}

int Statistics::min() const
{
  return min_;
}

double Statistics::average() const
{
  if (!elementsNum_)
  {
    throw std::invalid_argument("division by zero");
  }
  return (sum_ / (double)elementsNum_);
}

unsigned int Statistics::positiveNum() const
{
  return positiveNum_;
}

unsigned int Statistics::negativeNum() const
{
  return negativeNum_;
}

long long int Statistics::oddsSum() const
{
  return oddsSum_;
}

long long int Statistics::evensSum() const
{
  return evensSum_;
}

bool Statistics::firstEqLast() const
{
  if (!elementsNum_)
  {
    throw std::invalid_argument ("no elements");
  }
  return (first_ == last_);
}

bool Statistics::empty() const
{
  return (!elementsNum_);
}
