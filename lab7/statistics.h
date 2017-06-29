#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics
{
public:
  Statistics();
  void operator()(int);

  int max() const;                   // (1)
  int min() const;                   // (2)

  double average()           const;  // (3)

  unsigned int positiveNum()  const; // (4)
  unsigned int negativeNum()  const; // (5)

  long long int oddsSum()    const;  // (6)
  long long int evensSum()   const;  // (7)

  bool firstEqLast() const;          // (8)
  bool empty()       const;

private:
  int max_;
  int min_;

  int first_;
  int last_;

  unsigned int positiveNum_;
  unsigned int negativeNum_;
  unsigned int elementsNum_;

  long long int oddsSum_;
  long long int evensSum_;
  long long int sum_;
};

#endif // STATISTICS_H
