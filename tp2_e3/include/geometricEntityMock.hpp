#pragma once
#include "geometricEntity.hpp"

class geometricEntityMock : public geometricEntity {
private:
  char color;

public:
  geometricEntityMock(char color) : geometricEntity(color){};
  double getArea() { return 0.0; };
  double getPerimeter() { return 0.0; };
  bool draw(char **map, int x, int y) { return true; };
};
