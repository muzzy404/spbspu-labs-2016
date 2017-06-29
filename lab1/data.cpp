#include "data.h"

#include <string>
#include <vector>
#include <cstdlib>    // RAND_MAX and std::rand
#include <stdexcept>  // invalid_argument

SortType defineSortType(const std::string & str)
{
  if (str == "ascending")
  {
    return ASCENDING;
  }
  else if (str == "descending")
  {
    return DESCENDING;
  }
  return UNDEFINED;
}

std::vector<int> readIntsTillZero()
{
  std::vector<int> data;
  while(true)
  {
    int elem;
    std::cin >> elem;

    if (std::cin.fail())
    {
      if ((std::cin.eof()) && (data.empty())) // empty input
      {
        break;
      }
      throw std::ios_base::failure("invalid input");
    }

    if (elem == 0)
    {
      break;
    }
    data.push_back(elem);
  }

  return data;
}

void eraseEvenNumbers(std::vector<int> & v)
{
  for(auto it = v.begin(); it != v.end();)
  {
    if ((*it % 2) == 0)
    {
      it = v.erase(it);
      continue;
    }
    ++it;
  }
}

void insertTripleNumAfterOdds(std::vector<int> & v, int num)
{
  for(auto it = v.begin(); it != v.end(); ++it)
  {
    if ((*it % 3) == 0)
    {
      for (int i = 0; i < 3; it = v.insert(++it, num), ++i);
    }
  }
}

void fillRandom(double * array, const int size)
{
  if ((array == nullptr) || (size < 0))
  {
    throw std::invalid_argument("invalid request");
  }
  for(int i = 0; i < size; i++)
  {
    array[i] = (2.0 * std::rand() / RAND_MAX) - 1.0;
  }
}

