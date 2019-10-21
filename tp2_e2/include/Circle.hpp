#pragma once
#include "geometricEntity.hpp"

class Circle : public geometricEntity {
private:
  int radius;
  int Cx;
  int Cy;

public:
  Circle(char color, int radius, int Cx, int Cy);
  ~Circle();
  double getPerimeter();
  double getArea();
  bool draw(char **map, int x, int y);
};
