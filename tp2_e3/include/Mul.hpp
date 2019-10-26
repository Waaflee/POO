#pragma once
#include "Operation.hpp"

#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class Mul : public XmlRpcServerMethod {
private:
  std::list<Operation> *operationlist;

public:
  Mul(XmlRpcServer *s, std::list<Operation> &operationlist)
      : XmlRpcServerMethod("mul", s) {
    this->operationlist = &operationlist;
  }

  void execute(XmlRpcValue &params, XmlRpcValue &result) {
    result = double(params[0]) * double(params[1]);
    operationlist->push_back(
        Operation(double(params[0]), double(params[1]), "*"));
  }
};
