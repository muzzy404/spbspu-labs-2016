#include "statistics.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>

int main()
{
  Statistics s = std::for_each(std::istream_iterator<int>(std::cin),
                               std::istream_iterator<int>(),
                               Statistics());
  if (!std::cin.eof())
  {
    std::cerr << "wrong data format\n";
    return 1;
  }
  if (s.empty())
  {
    std::cout << "No Data\n";
    return 0;
  }

  std::cout << "Max: "        << s.max();
  std::cout << "\nMin: "      << s.min();
  std::cout << "\nMean: "     << std::fixed << std::setprecision(1) << s.average();
  std::cout << "\nPositive: " << s.positiveNum();
  std::cout << "\nNegative: " << s.negativeNum();
  std::cout << "\nOdd Sum: "  << s.oddsSum();
  std::cout << "\nEven Sum: " << s.evensSum();
  std::cout << "\nFirst/Last Equal: " << (s.firstEqLast() ? "yes\n" : "no\n");

  return 0;
}
