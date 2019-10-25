#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class NRoot : public XmlRpcServerMethod
{
public:
 NRoot(XmlRpcServer* s) : XmlRpcServerMethod("nroot", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
      result = std::pow(double(params[0]), 1 / double(params[1]));
  }
};
