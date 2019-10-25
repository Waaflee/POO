#include "../include/Calculator.hpp"

Calculator::Calculator(XmlRpcServer *s) {
  div = new Div(s, historial);
  mul = new Mul(s);
  nroot = new NRoot(s);
  pow = new Pow(s);
  res = new Res(s);
  sum = new Sum(s);
}
Calculator::~Calculator() {
  delete div;
  delete mul;
  delete nroot;
  delete pow;
  delete res;
  delete sum;
}
