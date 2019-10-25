#include "../include/Circle.hpp"
#include <string>

Circle::Circle(char color, int radius, int Cx, int Cy)
    : geometricEntity(color) {
  this->radius = radius;
  this->Cx = Cx;
  this->Cy = Cy;
}

Circle::~Circle() {}
double Circle::getArea() { return M_PI * (radius * radius); }
double Circle::getPerimeter() { return M_PI * (2 * radius); }
bool Circle::draw(char **map, int x, int y) {
  try {
    if (Cx + radius >= x) {
      throw std::string("Exceeded size right x");
    };
    if (Cx - radius < 0) {
      throw std::string("Exceeded size left x");
    };
    if (Cy + radius >= y) {
      throw std::string("Exceeded size under y");
    };
    if (Cy - radius < 0) {
      throw std::string("Exceeded size over y");
    };
  } catch (std::string e) {
    return false;
  }

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (manhattanDistance(i, j, Cx, Cy) == radius) {
        map[j][i] = getColor();
      }
    }
  }
  return true;
}
