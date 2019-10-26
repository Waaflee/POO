#pragma once
#include "../lib/XmlRpc.h"
#include "Operation.hpp"
#include <cmath>
using namespace XmlRpc;

class NRoot : public XmlRpcServerMethod {
private:
  std::list<Operation> *operationlist;

public:
  NRoot(XmlRpcServer *s, std::list<Operation> &operationlist)
      : XmlRpcServerMethod("nroot", s) {
    this->operationlist = &operationlist;
  }

  void execute(XmlRpcValue &params, XmlRpcValue &result) {
    result = std::pow(double(params[0]), 1 / double(params[1]));
    operationlist->insert(operationlist->end(),
        Operation(double(params[0]), double(params[1]), "^1/"));
  }
};
