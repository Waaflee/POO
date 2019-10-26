#include <string>
#include <iostream>
class Operation {
private:
  double operando1;
  double operando2;
  std::string operador;
public:
  Operation(double op1, double op2, std::string operand);
  ~Operation();
  std::string toString();
};
