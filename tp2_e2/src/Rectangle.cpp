#include "../include/Rectangle.hpp"
#include <iostream>
using namespace std;
Rectangle::Rectangle(char color, int w, int h, int x, int y)
    : geometricEntity(color) {
  this->width = abs(w);
  this->height = abs(h);
  this->Ax = abs(x);
  this->Ay = abs(y);
}

Rectangle::~Rectangle() {}
double Rectangle::getArea() { return double(this->height * this->height); }
double Rectangle::getPerimeter() {
  return double(2 * this->height + 2 * this->height);
}
bool Rectangle::draw(char **map, int x, int y) {
  try {
    if (Ax + width > x) {
      throw std::string("Exceeded size x");
    };
    if (Ay + height > y) {
      throw std::string("Exceeded size y");
    };
  } catch (std::string e) {
    std::cout << e << std::endl;
    return false;
  }
  if (width == 0 || height == 0) {
    return true;
  }
  try {

    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if ((i >= Ax && (i - Ax) < width - 1) &&
            (j == Ay || j == (Ay + height - 1))) {
          map[j][i] = getColor();
        }
        if ((i == Ax || i == Ax + width - 1) &&
            (j >= Ay && j <= Ay + height - 1)) {
          map[j][i] = getColor();
        }
      }
    }
  } catch (...) {
    cout << "Something happened...[Rectangle] " << Ax << Ay << width << height
         << endl;
  }
  return true;
}
