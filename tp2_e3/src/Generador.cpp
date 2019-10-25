#include "../include/Generador.hpp"

Generador::Generador(string file, bool diffColors, int rx, int ry, char fill) {

  this->fileName = file;
  this->differentColors = diffColors;
  this->res_x = rx;
  this->res_y = ry;
  this->mapFill = fill;
  this->generateMap();
}

Generador::~Generador() { delete[] map; }
void Generador::generateMap() {
  map = new char *[res_y];
  for (int i = 0; i < res_y; ++i) {
    map[i] = new char[res_x];
    for (int j = 0; j < res_x; j++) {
      map[i][j] = 'o';
    }
  }
}
bool Generador::compareMap(char **otherMap) {
  for (int i = 0; i < res_y; i++) {
    for (int j = 0; j < res_x; j++) {
      if (map[i][j] != otherMap[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void Generador::printMap() {
  for (int i = res_y - 1; i >= 0; i--) {
    for (int j = 0; j < res_x; j++) {
      std::cout << map[i][j];
    }
    std::cout << std::endl;
  }
}

list<string> Generador::analyzeFile() { return std::list<string>(); }
