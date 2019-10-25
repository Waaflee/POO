#include <string>

class Operation {
private:
  double operando1;
  double operando2;
  std::string operador;
public:
  std::string toString();
  Operation(double op1, double op2, std::string operand);
  ~Operation();
};
