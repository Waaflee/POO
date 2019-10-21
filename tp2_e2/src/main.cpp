#include "../include/Generador.hpp"
#include "../include/Rectangle.hpp"
#include "../include/Triangle.hpp"

int main(int argc, char **argv) {

  // Rectangle rectangle = Rectangle('a', 2, 2, 0, 0);
  Triangle triangle = Triangle('a', 0, 0, 0, 3, 3, 3);

  int rows = 4, cols = 4;
  char **testmap = new char *[rows];
  for (int i = 0; i < rows; ++i) {
    testmap[i] = new char[cols];
    for (int j = 0; j < cols; j++) {
      testmap[i][j] = 'o';
    }
  }
  // testmap[0][0] = rectangle.getColor();
  // testmap[0][1] = rectangle.getColor();
  // testmap[1][0] = rectangle.getColor();
  // testmap[1][1] = rectangle.getColor();
  // testmap[2][0] = rectangle.getColor();
  // testmap[2][1] = rectangle.getColor();

  testmap[0][0] = triangle.getColor();
  // testmap[0][1] = triangle.getColor();
  // testmap[0][2] = triangle.getColor();
  testmap[1][0] = triangle.getColor();
  testmap[1][1] = triangle.getColor();
  // testmap[1][2] = triangle.getColor();
  Generador gen = Generador("input", true, cols, rows);
  gen.printMap();
  std::cout << "--------------" << std::endl;
  triangle.draw(gen.getMap(), cols, rows);
  // rectangle.draw(gen.getMap(), cols, rows);
  gen.printMap();
  return 0; // make sure your main returns int
}
