#ifndef SORTING
#define SORTING

#include "data.h"

#include <string>

#include <stdexcept>
#include <iostream>

//access by index for vectors
template< class Container >
struct IndexAccess
{
  typedef typename std::size_t Iterator;
  typedef typename Container::value_type ElementType;
  static Iterator begin(Container &)
  {
    return 0;
  };
  static Iterator end(Container &vector)
  {
    return vector.size();
  };
  static ElementType &getElement(Iterator i, Container &vector)
  {
    return vector[i];
  };
};

//access by method at
template< class Container >
struct AtAccess
{
  typedef typename std::size_t Iterator;
  typedef typename Container::value_type ElementType;
  static Iterator begin(Container &)
  {
    return 0;
  };
  static Iterator end(Container &vector)
  {
    return vector.size();
  };
  static ElementType &getElement(Iterator i, Container &vector)
  {
    return vector.at(i);
  };
};

//access by iterators for forward list
template< class Container >
struct IteratorAccess
{
  typedef typename Container::value_type ElementType;
  typedef typename Container::iterator Iterator;
  static Iterator begin(Container &frdList)
  {
    return frdList.begin();
  };
  static Iterator end(Container &frdList)
  {
    return frdList.end();
  };
  static ElementType &getElement(Iterator i, Container &)
  {
    return *i;
  };
};

template< template<typename> class Access, typename Container >
void sort(Container & container, SortType type)
{
  typedef Access<Container> access;
  typedef typename Access<Container>::Iterator Iterator;

  if (access::begin(container) == access::end(container))
  {
    return;
  }

  if (type == UNDEFINED)
  {
    throw std::invalid_argument("wrong preference request for sort method");
  }

  //sorting
  for(Iterator i = access::begin(container); i != access::end(container); ++i)
  {
    for(Iterator j = i; j != access::end(container); ++j)
    {

     if ( ((type == ASCENDING)  && (access::getElement(i, container) >
                                    access::getElement(j, container) )) ||
          ((type == DESCENDING) && (access::getElement(i, container) <
                                    access::getElement(j, container) )) )
      {
        std::swap(access::getElement(i, container),
                  access::getElement(j, container));
      }

    }
  }

}

#endif // SORTING
