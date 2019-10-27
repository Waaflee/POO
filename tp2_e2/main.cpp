
#include "include/Generador.hpp"

int main(int argc, char **argv) {
  Generador gen = Generador("../input", false);
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
