#pragma once
#include <cmath>
#include <iostream>
#include <string>

class geometricEntity {
protected:
  char color;

public:
  geometricEntity(char color) { this->color = color; };
  virtual ~geometricEntity(){};
  // ~geometricEntity(){};
  virtual double getArea() = 0;
  // double getArea() { return 0.0; };
  virtual double getPerimeter() = 0;
  // double getPerimeter() { return 0.0; };
  virtual bool draw(char **map, int x, int y) = 0;
  // bool draw(char **map, int x, int y) { return false; };

  double euclideanDistance(int Ax, int Ay, int Bx, int By) {
    using namespace std;
    return double(sqrt(abs(pow(Bx - Ax, 2)) + abs(pow(By - Ay, 2))));
  }
  int manhattanDistance(int Ax, int Ay, int Bx, int By) {
    return abs(Bx - Ax) + abs(By - Ay);
  }
  char getColor() { return color; };
};
