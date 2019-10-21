#pragma once
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Generador {
  string fileName;
  bool differentColors;
  char **map;
  int res_x;
  int res_y;
  char mapFill;

public:
  Generador(string file, bool diffColors, int rx, int ry, char fill = 'o');
  ~Generador();
  char **getMap() { return map; };
  void generateMap();
  list<string> analyzeFile();
  void printMap();
  bool compareMap(char **otherMap);
};
