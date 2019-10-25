#include "lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

// The server
XmlRpcServer s;

// The Hello method. No arguments, result is "Hello".
class Sum : public XmlRpcServerMethod
{
public:
  Sum(XmlRpcServer* s) : XmlRpcServerMethod("sum", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    result = int(params[0]) + int(params[1]);
  }
} method_sum(&s);    // This constructor registers the method with the server
class Res : public XmlRpcServerMethod
{
public:
  Res(XmlRpcServer* s) : XmlRpcServerMethod("res", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    result = int(params[0]) - int(params[1]);
  }
} method_res(&s);    // This constructor registers the method with the server
class Mul : public XmlRpcServerMethod
{
public:
  Mul(XmlRpcServer* s) : XmlRpcServerMethod("mul", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    result = int(params[0]) * int(params[1]);
  }
} method_mul(&s);    // This constructor registers the method with the server

class Div : public XmlRpcServerMethod
{
public:
  Div(XmlRpcServer* s) : XmlRpcServerMethod("div", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
    try {
      result = int(params[0]) / int(params[1]);
    } catch(...) {
      result = 0;
    }
  }
} method_div(&s);
   // This constructor registers the method with the server
class Pow : public XmlRpcServerMethod
{
public:
 Pow(XmlRpcServer* s) : XmlRpcServerMethod("pow", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
      result = std::pow(int(params[0]), int(params[1]));
  }
} method_pow(&s);    // This constructor registers the method with the server

class NRoot : public XmlRpcServerMethod
{
public:
 NRoot(XmlRpcServer* s) : XmlRpcServerMethod("nroot", s) {}

  void execute(XmlRpcValue& params, XmlRpcValue& result)
  {
      result = std::pow(int(params[0]), 1 / int(params[1]));
  }
} method_nroot(&s);    // This constructor registers the method with the server



// The port to use
const int PORT = 8080;

int main(int argc, char* argv[]) {

  // Create the server socket on the specified port
  s.bindAndListen(PORT);

  // Wait for requests and process indefinitely (Ctrl-C to exit)
  s.work(-1.0);

  return 0;
}
