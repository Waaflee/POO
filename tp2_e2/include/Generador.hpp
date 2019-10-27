#pragma once
#include "FileParser.hpp"
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Generador {
  vector<string> report;
  // FileParser *parser;
  string fileName;
  bool differentColors;
  char **map;
  int res_x;
  int res_y;
  string mapFill;
  bool mapCreated;

public:
  Generador(string file, bool diffColors);
  Generador(string file, bool diffColors, int x, int y);
  ~Generador();
  char **getMap() { return map; };
  void generateMap();
  void analyzeFile();
  void printMap();
  bool compareMap(char **otherMap);
  vector<string> getReport() { return report; }
  int getRX() { return res_x; };
  int getRY() { return res_y; };
};
