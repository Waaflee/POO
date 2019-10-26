#include "../include/Operation.hpp"
Operation::Operation(double op1, double op2, std::string operand) {
  this->operando1 = op1;
  this->operando2 = op2;
  this->operador = operand;
}
Operation::~Operation() {}
std::string Operation::toString() const {
  return (std::to_string(operando1) + " " + operador + " " +
          std::to_string(operando2));
}
