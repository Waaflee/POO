#include "../include/Calculator.hpp"

Calculator::Calculator(XmlRpcServer *s) {
  div = new Div(s, historial);
  mul = new Mul(s, historial);
  nroot = new NRoot(s, historial);
  pow = new Pow(s, historial);
  res = new Res(s, historial);
  sum = new Sum(s, historial);
}
Calculator::~Calculator() {
  delete div;
  delete mul;
  delete nroot;
  delete pow;
  delete res;
  delete sum;
}
