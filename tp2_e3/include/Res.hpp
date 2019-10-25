#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class Res : public XmlRpcServerMethod
{
public:
  Res(XmlRpcServer* s) : XmlRpcServerMethod("res", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    result = double(params[0]) - double(params[1]);
  }
};
