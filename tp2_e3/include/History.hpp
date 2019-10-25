#pragma once
#include "../lib/XmlRpc.h"
#include <cmath>
#include "Operation.hpp"

using namespace XmlRpc;

class History : public XmlRpcServerMethod
{
private:
  std::list<Operation> *operationlist;
public:
  History(XmlRpcServer* s, std::list<Operation> *operationlist) : XmlRpcServerMethod("history", s) {
    this->operationlist = operationlist;
  }

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    result = operationlist;
  }
};
