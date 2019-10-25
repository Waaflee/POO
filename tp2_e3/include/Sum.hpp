#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class Sum : public XmlRpcServerMethod
{
public:
  Sum(XmlRpcServer* s) : XmlRpcServerMethod("sum", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    result = double(params[0]) + double(params[1]);
  }
};
