#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class Mul : public XmlRpcServerMethod
{
public:
  Mul(XmlRpcServer* s) : XmlRpcServerMethod("mul", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    result = double(params[0]) * double(params[1]);
  }
};
