#include "lib/XmlRpc.h"
#include <iostream>

using namespace XmlRpc;

int main(int argc, char* argv[]) {
    std::string opcion = " ";
    float a1,a2;
    while(opcion!="t"){
    char opcion;
    std::cout << "=========================================" << std::endl << "CALCULADORA DISTRIBUIDA CON RPC" << std::endl << "=========================================" << std::endl;
    std::cout << "a. Adicion" << std::endl << "s. Sustraccion" << std::endl << "m. Multiplicacion" << std::endl << "d. Division" << std::endl << "p. Potenciacion" << std::endl << "r. Radicacion" << std::endl << "h. Historial" << std::endl << "t. Terminar" << std::endl << "*****************************************" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opcion;
    std::cout << "Argumento1: ";
    std::cin >> a1;
    std::cout << "Argumento2: ";
    std::cin >> a2;
    
  if (argc != 3) {
    std::cerr << "Usage: HelloClient serverHost serverPort\n";
    return -1;
  }
  const char* hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a client and connect to the server at hostname:port
  XmlRpcClient client(hostname, port);

  XmlRpcValue noArgs, result;

noArgs[0] = opcion;
  // Call the remote procedure Hello and print the result value
  if (client.execute("Hellou", noArgs, result))
    std::cout << result << std::endl;
  }
}
