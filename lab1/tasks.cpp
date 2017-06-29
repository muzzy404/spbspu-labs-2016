#include "tasks.h"
#include "sorting.h"
//#include "data.h"

#include <vector>
#include <forward_list>
#include <stdexcept>
#include <memory>        // std::unique_ptr
#include <fstream>       // std::ifstream
#include <cstdlib>       // std::srand
#include <ctime>         // std::time


void makeTask1(int argc, char * argv[])
{
  if (argc != 3)
  {
    throw std::invalid_argument("invalid number of arguments for task 1");
  }

  SortType sortType = defineSortType(argv[2]);
  if (sortType == UNDEFINED)
  {
    throw std::invalid_argument("undefined preference of sorting");
  }

  std::vector<int> vector1 = makeDataVector<int>();
  std::vector<int> vector2 = vector1;
  // copying data to forward list
  std::forward_list<int> forwardList;
  for(auto it = vector1.end(); it != vector1.begin();
                             --it, forwardList.push_front(*it));
  // sorting
  sort<IndexAccess>(vector1, sortType);
  sort<AtAccess>(vector2, sortType);
  sort<IteratorAccess>(forwardList, sortType);

  // printing
  printContainer(vector1);
  printContainer(vector2);
  printContainer(forwardList);
}

void makeTask2(int argc, char * argv[])
{
  if (argc != 3)
  {
    throw std::invalid_argument("invalid number of arguments for task 2");
  }

  std::ifstream textFile(argv[2], std::ifstream::binary);
  if (!textFile.is_open())
  {
    throw std::invalid_argument("invalid file name for task 2");
  }

  // getting the length of file
  textFile.seekg(0,textFile.end);
  const int length = textFile.tellg();
  textFile.seekg(0,textFile.beg);

  // array for reading in smart pointer
  std::unique_ptr<char[]> arrayC(new char[length]);
  textFile.read(&(arrayC[0]),length);

  textFile.close();

  // if the number of symbols has changed
  if (textFile.gcount() != length)
  {
    throw std::ios_base::failure
          ("the length of file has been changed while reading in task 2");
  }

  // copying array to vector
  std::vector<char> dataVector(&(arrayC[0]), &(arrayC[0]) + length);

  for(const char ch : dataVector)
  {
    std::cout << ch;
  }

}

void makeTask3(int argc)
{
  if (argc != 2)
  {
    throw std::invalid_argument("invalid number of arguments for task 3");
  }

  std::vector<int> ints = readIntsTillZero();

  switch (*(--ints.end())) // the last number of vector
  {
    case 1:
      eraseEvenNumbers(ints);
      break;
    case 2:
      insertTripleNumAfterOdds(ints, 1);
      break;
  }

  printContainer(ints);
}

void makeTask4(int argc, char * argv[])
{
  if (argc != 4)
  {
    throw std::invalid_argument("invalid number of arguments for task 4");
  }

  SortType sortType = defineSortType(argv[2]);
  if (sortType == UNDEFINED)
  {
    throw std::invalid_argument("undefined preference of sorting");
  }

  int dimension = std::stoi(argv[3]);
  if (dimension < 0)
  {
    throw std::invalid_argument("invalid dimension request");
  }

  std::srand(std::time(0)); // use current time as seed for random generator

  std::vector<double> data(dimension);

  fillRandom(&(data[0]), dimension);

  std::cout.setf(std::ios::fixed);
  std::cout.precision(5);
  printContainer(data);

  sort<IndexAccess>(data, sortType);

  printContainer(data);
}
