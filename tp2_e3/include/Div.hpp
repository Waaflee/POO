#pragma once
#include "Operation.hpp"
#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class Div : public XmlRpcServerMethod
{
private:
  std::list<Operation> *operationlist;
public:
  Div(XmlRpcServer* s, std::list<Operation> *operationlist) : XmlRpcServerMethod("div", s) {
    this->operationlist = operationlist;
  }

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    try {
      result = double(params[0]) / double(params[1]);
    } catch(...) {
      result = 0.0;
    }
    operationlist->push_back(Operation(double(params[0]), double(params[1]), "/"));
  }
};
