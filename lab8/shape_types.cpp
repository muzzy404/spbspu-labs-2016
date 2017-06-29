#include "shape_types.h"

ShapeTypes::TypesMap ShapeTypes::typesMap({{ "CIRCLE",   CIRCLE   },
                                           { "TRIANGLE", TRIANGLE },
                                           { "SQUARE",   SQUARE   },});

ShapeTypes::Type ShapeTypes::determineType(std::string & str)
{
  TypesMap::const_iterator type = typesMap.find(str);
  if (type != typesMap.end())
  {
    return type->second;
  }
  return UNKNOWN;
}
