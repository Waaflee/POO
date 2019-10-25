#include "include/Calculator.hpp"
#include "lib/XmlRpc.h"
#include <cmath>
using namespace XmlRpc;

// The server
XmlRpcServer s;

// The port to use
const int PORT = 8080;

int main(int argc, char* argv[]) {

  Calculator calc(&s);
  // Create the server socket on the specified port
  s.bindAndListen(PORT);

  // Wait for requests and process indefinitely (Ctrl-C to exit)
  s.work(-1.0);

  return 0;
}
