#include "../include/Triangle.hpp"
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

// void followLine(int ax, int ay, int bx, int by);

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

// void followLine(int ax, int ay, int bx, int by) {
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//       /* code */
//     }
//   }
// }
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
    // double isOnRect =
    // ((by - ay) / (bx - ay)) * (currentx - ax) - (currenty - ay);
    if (ax == 0 && bx == 0) {
      if (currentx != 0) {
        return false;
      }
    }
    if (ay == 0 && by == 0) {
      if (currenty != 0) {
        return false;
      }
    }
    if (ax == bx) {
      if (currentx != ax) {
        return false;
      } else {
        return true;
      }
    }
    if (ay == by) {
      if (currenty != ay) {
        return false;
      } else {
        return true;
      }
    }
    try {
      int xside = (currentx - ax) / (bx - ax);
      int yside = (currenty - ay) / (by - ay);
      if (abs(xside - yside) == 0) {
        return true;
      }
    } catch (...) {
      std::cout << "something happened";
    }
    // int distance = manhattanDistance(ax, ay, bx, by);
    // int currentDistance = distance;
    // std::list<int> distances;
    // for (int i = 0; i < distance; i++) {
    //   for (int j = -1; j < 2; j++) {
    //     for (int k = -1; k < 2; k++) {
    //       if (j == 0 && k == 0) {
    //         continue;
    //       }
    //       currentDistance =
    //           manhattanDistance(currentx + j, currenty + k, bx, by);
    //
    //       if (currentDistance < distance) {
    //         distances.push_back(currentDistance);
    //       }
    //     }
    //   }
    // }
    // std::list<int>::iterator minDistance =
    //     std::min_element(distances.begin(), distances.end());
    // std::cout << "minumun Distance: " << *minDistance << std::endl;
    // for (int j = -1; j < 2; j++) {
    //   for (int k = -1; k < 2; k++) {
    //     if (j == 0 && k == 0) {
    //       continue;
    //     }
    //     currentDistance = manhattanDistance(currentx + j, currenty + k, bx,
    //     by);
    //
    //     if (currentDistance == *minDistance) {
    //       return true;
    //     }
    //   }
    // }
  }
  return false;
}

bool Triangle::draw(char **map, int x, int y) {
  try {
    if (Ax > x) {
      throw string("Exceeded size Ax");
    };
    if (Ay > y) {
      throw string("Exceeded size Ay");
    };
    if (Bx > x) {
      throw string("Exceeded size Bx");
    };
    if (By > y) {
      throw string("Exceeded size By");
    };
    if (Cx > x) {
      throw string("Exceeded size Cx");
    };
    if (Cy > y) {
      throw string("Exceeded size Cy");
    };
  } catch (string e) {
    cout << e << endl;
    return false;
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      if (isOnRect(Ax, Ay, Bx, By, i, j) || isOnRect(Ax, Ay, Cx, Cy, i, j) ||
          isOnRect(Cx, Cy, Bx, By, i, j)) {
        map[j][i] = getColor();
      }
    }
  }

  return true;
}
