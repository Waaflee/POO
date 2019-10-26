#pragma once
#include "Div.hpp"
#include "Mul.hpp"
#include "NRoot.hpp"
#include "Pow.hpp"
#include "Res.hpp"
#include "Sum.hpp"
#include "Operation.hpp"

#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class Calculator {
private:
  Div *div;
  Mul *mul;
  NRoot *nroot;
  Pow *pow;
  Res *res;
  Sum *sum;
  std::list<Operation>historial;
public:
  Calculator(XmlRpcServer* s);
  ~Calculator();
};
