#pragma once
#include "../lib/XmlRpc.h"
#include "Operation.hpp"
#include <cmath>
using namespace XmlRpc;

class Sum : public XmlRpcServerMethod {
private:
  std::list<Operation> *operationlist;

public:
  Sum(XmlRpcServer *s, std::list<Operation> &operationlist)
      : XmlRpcServerMethod("sum", s) {
    this->operationlist = &operationlist;
  }

  void execute(XmlRpcValue &params, XmlRpcValue &result) {
    result = double(params[0]) + double(params[1]);
    operationlist->insert(operationlist->end(),
        Operation(double(params[0]), double(params[1]), "+"));
  }
};
