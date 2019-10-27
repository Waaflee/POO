
#include "include/Generador.hpp"

int main(int argc, char **argv) {
  string inputFile;
  cout << "Ingrese nombre del archivo de entrada" << endl;
  cin >> inputFile;
  cout << endl;
  Generador gen = Generador(inputFile, false);
  // gen.analyzeFile();
  gen.printMap();
  gen.printMap("../map");
  ofstream report;
  report.open("../report");
  for (auto const &i : gen.getReport()) {
    cout << i;
    report << i;
  }
  cout << endl;
  report.close();

  return 0;
}
