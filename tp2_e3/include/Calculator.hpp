#pragma once
#include "Div.hpp"
#include "History.hpp"
#include "Mul.hpp"
#include "NRoot.hpp"
#include "Operation.hpp"
#include "Pow.hpp"
#include "Res.hpp"
#include "Sum.hpp"

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
  History *log;
  std::list<Operation> historial;

public:
  Calculator(XmlRpcServer *s);
  ~Calculator();
};
