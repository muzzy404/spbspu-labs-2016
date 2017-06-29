#ifndef SHAPE_TYPES_H
#define SHAPE_TYPES_H

#include <map>
#include <string>

class ShapeTypes
{
public:
  typedef enum
  {
    CIRCLE,
    TRIANGLE,
    SQUARE,
    UNKNOWN,
  } Type;
  static Type determineType(std::string &);
private:
  typedef std::map<std::string, Type> TypesMap;
  static TypesMap typesMap;
};

#endif // SHAPE_TYPES_H
