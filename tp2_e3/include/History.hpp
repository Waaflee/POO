#pragma once
#include "../lib/XmlRpc.h"
#include "Operation.hpp"
#include <cmath>

using namespace XmlRpc;

class History : public XmlRpcServerMethod {
private:
  std::list<Operation> *operationlist;

public:
  History(XmlRpcServer *s, std::list<Operation> &operationlist)
      : XmlRpcServerMethod("history", s) {
    this->operationlist = &operationlist;
  }

  void execute(XmlRpcValue &params, XmlRpcValue &result) {
    std::string buffer = "Historial de Operaciones:\n";
    for (auto const &i : *operationlist) {
      buffer += i.toString() + "\n";
      std::cout << i.toString() + "\n";
    }
    result = operationlist;
  }
};
