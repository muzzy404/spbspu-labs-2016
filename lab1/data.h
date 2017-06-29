#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <iostream>

enum SortType
{
  ASCENDING,
  DESCENDING,
  UNDEFINED,
};

SortType defineSortType(const std::string &);

std::vector<int> readIntsTillZero();

void eraseEvenNumbers(std::vector<int> &);
void insertTripleNumAfterOdds(std::vector<int> &, int);

void fillRandom(double * array, const int size);

template < typename T >
std::vector<T> makeDataVector()
{
  std::vector<T> vector;
  while(true)
  {
    T elem;
    std::cin >> elem;

    if (std::cin.fail())
    {
      if (std::cin.eof())
      {
        break;
      }
      throw std::ios_base::failure("invalid input");
    }

    vector.push_back(elem);
  }
  return vector;
}

template < class Container >
void printContainer(const Container & container)
{
  for(const typename Container::value_type elem : container)
  {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

#endif // DATA_H
