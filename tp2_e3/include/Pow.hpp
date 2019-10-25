#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class Pow : public XmlRpcServerMethod
{
public:
 Pow(XmlRpcServer* s) : XmlRpcServerMethod("pow", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
      result = std::pow(double(params[0]), double(params[1]));
  }
};
