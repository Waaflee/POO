#pragma once
#include "geometricEntity.hpp"

class Rectangle : public geometricEntity {
private:
  int width;
  int height;
  int Ax;
  int Ay;

public:
  Rectangle(char color, int w, int h, int x, int y);
  ~Rectangle();
  double getPerimeter();
  double getArea();
  bool draw(char **map, int x, int y);
};
