#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "geometricEntity.hpp"
#include <fstream>
#include <list>
#include <string>
#include <vector>
using namespace std;

class FileParser {
private:
  // std::list<geometricEntity> figures;
  int currentColor;

public:
  vector<vector<string>> lines;
  void split(std::string str, std::string splitBy,
             std::vector<std::string> &tokens);
  FileParser(std::string filename);
  ~FileParser();
};
