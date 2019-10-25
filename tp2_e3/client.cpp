#include "lib/XmlRpc.h"
#include <iostream>

using namespace XmlRpc;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: HelloClient serverHost serverPort\n";
    return -1;
  }
  const char* hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a client and connect to the server at hostname:port
  XmlRpcClient client(hostname, port);

  XmlRpcValue noArgs, result;

noArgs[0] = 27;
  // Call the remote procedure Hello and print the result value
  if (client.execute("Hellou", noArgs, result))
    std::cout << result << std::endl;
}
