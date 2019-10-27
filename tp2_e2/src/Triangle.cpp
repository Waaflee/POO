#include "../include/Triangle.hpp"
using namespace std;

Triangle::Triangle(char color, int Ax, int Ay, int Bx, int By, int Cx, int Cy)
    : geometricEntity(color) {
  this->Ax = Ax;
  this->Ay = Ay;
  this->Bx = Bx;
  this->By = By;
  this->Cx = Cx;
  this->Cy = Cy;
};

Triangle::~Triangle(){};

double Triangle::getArea() {
  double base = abs(Bx - Ax);
  double height = abs(Cy - By);
  return base * height * 0.5;
}
double Triangle::getPerimeter() {
  double side1 = sqrt(pow(abs(Bx - Ax), 2) + pow(abs(By - Ay), 2));
  double side2 = sqrt(pow(abs(Cx - Ax), 2) + pow(abs(Cy - Ay), 2));
  double side3 = sqrt(pow(abs(Cx - Bx), 2) + pow(abs(Cy - By), 2));
  return side1 + side2 + side3;
}

bool Triangle::isInBetween(int a, int b, int current) {
  if (a < b) {
    if (current >= a && current <= b) {
      return true;
    }
  } else {
    if (current <= a && current >= b) {
      return true;
    }
  }
  return false;
};

bool Triangle::isOnRect(int ax, int ay, int bx, int by, int currentx,
                        int currenty) {
  if (isInBetween(ax, bx, currentx) && isInBetween(ay, by, currenty)) {
    if (ax == bx && currentx == ax) {
      return true;
    }
    if (ay == by && currenty == ay) {
      return true;
    }
    int dx = bx - ax;
    int dy = by - ay;
    // cout << currenty << ": " << int(round((currentx - ax)) * dy / dx + ay)
    // << endl;
    if (currenty == int(round((currentx - ax)) * dy / dx + ay)) {
      // cout << "Match!!" << endl;
      return true;
    }
  }
  return false;
}

bool Triangle::draw(char **map, int y, int x) {
  try {
    if (Ax >= x) {
      throw string("Exceeded size Ax");
    };
    if (Ay >= y) {
      throw string("Exceeded size Ay");
    };
    if (Bx >= x) {
      throw string("Exceeded size Bx");
    };
    if (By >= y) {
      throw string("Exceeded size By");
    };
    if (Cx >= x) {
      throw string("Exceeded size Cx");
    };
    if (Cy >= y) {
      throw string("Exceeded size Cy");
    };
  } catch (string e) {
    // cout << e << endl;
    return false;
  }
  try {
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if (isOnRect(Ax, Ay, Bx, By, i, j) || isOnRect(Ax, Ay, Cx, Cy, i, j) ||
            isOnRect(Cx, Cy, Bx, By, i, j)) {
          map[i][j] = getColor();
        }
      }
    }
  } catch (...) {
    cout << "Something happened...[Triangle] " << Ax << Ay << Bx << By << Cx
         << Cy << endl;
  }

  return true;
}
