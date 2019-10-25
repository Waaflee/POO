#include "../lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

class Div : public XmlRpcServerMethod
{
public:
  Div(XmlRpcServer* s) : XmlRpcServerMethod("div", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    try {
      result = double(params[0]) / double(params[1]);
    } catch(...) {
      result = 0.0;
    }
  }
};
