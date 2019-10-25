#pragma once
#include "geometricEntity.hpp"

class Triangle : public geometricEntity {
private:
  int Ax;
  int Ay;
  int Bx;
  int By;
  int Cx;
  int Cy;

public:
  Triangle(char color, int Ax, int Ay, int Bx, int By, int Cx, int Cy);
  ~Triangle();
  bool isInBetween(int a, int b, int current);
  bool isOnRect(int ax, int ay, int bx, int by, int currentx, int currenty);
  double getPerimeter();
  double getArea();
  bool draw(char **map, int x, int y);
};
