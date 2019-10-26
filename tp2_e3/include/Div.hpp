#pragma once
#include "../lib/XmlRpc.h"
#include "Operation.hpp"
#include <cmath>
using namespace XmlRpc;

class Div : public XmlRpcServerMethod {
private:
  std::list<Operation> *operationlist;

public:
  Div(XmlRpcServer *s, std::list<Operation> &operationlist)
      : XmlRpcServerMethod("div", s) {
    this->operationlist = &operationlist;
  }

  void execute(XmlRpcValue &params, XmlRpcValue &result) {
    try {
      result = double(params[0]) / double(params[1]);
    } catch (...) {
      result = 0.0;
    }
    operationlist->insert(
      operationlist->end(),Operation(double(params[0]), double(params[1]), "/"));
  }
};
