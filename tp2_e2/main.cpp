
#include "include/Generador.hpp"

int main(int argc, char **argv) {
  Generador gen = Generador("../input", false);
  // gen.analyzeFile();
  gen.printMap();
  for (auto const &i : gen.getReport()) {
    cout << i;
  }
  cout << endl;

  return 0;
}
