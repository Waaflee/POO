#include "../include/Generador.hpp"

Generador::Generador(string file, bool diffColors) {
  this->fileName = file;
  this->differentColors = diffColors;
  // this->parser = new FileParser(file);
  // this->res_x = stoi(parser->lines.at(0).at(0));
  // this->res_y = stoi(parser->lines.at(0).at(1));
  // this->generateMap();
  // this->mapCreated = true;
  this->analyzeFile();
}
Generador::Generador(string file, bool diffColors, int x, int y) {
  this->fileName = file;
  this->differentColors = diffColors;
  this->res_x = x;
  this->res_y = y;
  this->mapFill = "0";
  this->generateMap();
  this->mapCreated = true;
}

Generador::~Generador() { delete[] map; }

void Generador::generateMap() {
  map = new char *[res_y];
  for (int i = 0; i < res_y; ++i) {
    map[i] = new char[res_x];
    for (int j = 0; j < res_x; j++) {
      map[i][j] = mapFill[0];
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
void Generador::printMap(string mapfile) {
  ofstream report;
  report.open(mapfile);
  for (int i = res_y - 1; i >= 0; i--) {
    for (int j = 0; j < res_x; j++) {
      report << map[i][j];
    }
    report << std::endl;
  }
  report.close();
}
void Generador::analyzeFile() {
  FileParser parser(fileName);
  for (auto const &i : parser.lines) {
    switch (i.at(0)[0]) {
    case 'c':
      // Circle
      if (i.size() != 5) {
        report.push_back("Error (parametros invalidos)\n");
      } else {
        try {
          Circle c =
              Circle(i.at(1)[1], stoi(i.at(2)), stoi(i.at(3)), stoi(i.at(4)));
          if (!c.draw(getMap(), res_x, res_y)) {
            report.push_back("Error (fuera de rango)\n");
          } else {
            report.push_back("Circulo\t\t\t" + to_string(c.getColor()) +
                             "\t\t" + to_string(c.getPerimeter()) + "\t" +
                             to_string(c.getArea()) + "\n");
          }
        } catch (...) {
          report.push_back("Error (parametros invalidos)\n");
        }
      }
      break;
    case 't':
      // Triangle
      if (i.size() != 8) {
        report.push_back("Error (parametros invalidos)\n");
      } else {
        try {
          Triangle t =
              Triangle(i.at(1)[1], stoi(i.at(3)), stoi(i.at(2)), stoi(i.at(5)),
                       stoi(i.at(4)), stoi(i.at(7)), stoi(i.at(6)));
          if (!t.draw(getMap(), res_x, res_y)) {
            report.push_back("Error (fuera de rango)\n");
          } else {
            report.push_back("Triangulo\t\t" + to_string(t.getColor()) +
                             "\t\t" + to_string(t.getPerimeter()) + "\t" +
                             to_string(t.getArea()) + "\n");
          }
        } catch (...) {
          report.push_back("Error (parametros invalidos)\n");
        }
      }
      break;
    case 'r':
      // Rectangle
      if (i.size() != 6) {
        report.push_back("Error (parametros invalidos)\n");
      } else {
        Rectangle r = Rectangle(i.at(1)[1], stoi(i.at(3)), stoi(i.at(2)),
                                stoi(i.at(4)), stoi(i.at(5)));
        if (!r.draw(getMap(), res_x, res_y)) {
          report.push_back("Error (fuera de rango)\n");
        } else {
          report.push_back("Rectangulo\t\t" + to_string(r.getColor()) + "\t\t" +
                           to_string(r.getPerimeter()) + "\t" +
                           to_string(r.getArea()) + "\n");
        }
      }
      break;
    default:
      // // Resolution and fill setup
      if (i.size() >= 2 && i.size() <= 3) {
        try {
          res_x = stoi(i.at(0));
          res_y = stoi(i.at(1));
          if (i.size() == 3)
            mapFill = i.at(2);
          generateMap();
          mapCreated = true;
          report.push_back("Resolución: " + to_string(res_x) + "x" +
                           to_string(res_y) + "\n");
          report.push_back("Relleno: " + mapFill + "\n");
          report.push_back("Figura\t\t\tColor\t\tPerimetro\tSuperficie\n");
          break;
        } catch (...) {
          report.push_back("Error (parametros invalidos)\n");
        }
      }
      report.push_back("Error (la figura no existe)\n");
      break;
    }
  }
}
