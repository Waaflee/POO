#pragma once
#include "Operation.hpp"

#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class Pow : public XmlRpcServerMethod {
private:
  std::list<Operation> *operationlist;

public:
  Pow(XmlRpcServer *s, std::list<Operation> &operationlist)
      : XmlRpcServerMethod("pow", s) {
    this->operationlist = &operationlist;
  }

  void execute(XmlRpcValue &params, XmlRpcValue &result) {
    result = std::pow(double(params[0]), double(params[1]));
    operationlist->push_back(
        Operation(double(params[0]), double(params[1]), "^"));
  }
};
