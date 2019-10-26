#include "lib/XmlRpc.h"
#include <iostream>

using namespace XmlRpc;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: HelloClient serverHost serverPort\n";
    return -1;
  }
  const char *hostname = argv[1];
  int port = atoi(argv[2]);
  std::string opcion = " ";
  float a1, a2;
  while (true) {
    char opcion;
    std::cout << "=========================================" << std::endl
              << "CALCULADORA DISTRIBUIDA CON RPC" << std::endl
              << "=========================================" << std::endl;
    std::cout << "a. Adicion" << std::endl
              << "s. Sustraccion" << std::endl
              << "m. Multiplicacion" << std::endl
              << "d. Division" << std::endl
              << "p. Potenciacion" << std::endl
              << "r. Radicacion" << std::endl
              << "h. Historial" << std::endl
              << "t. Terminar" << std::endl
              << "*****************************************" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opcion;
    std::string rpcFunctionName;
    switch (opcion) {
    case 't':
      return 0;
      break;
    case 'h':
      break;
    case 'a':
    case 's':
    case 'm':
    case 'd':
    case 'p':
    case 'r':
      std::cout << "Argumento1: ";
      std::cin >> a1;
      std::cout << "Argumento2: ";
      std::cin >> a2;
      break;
    default:
      std::cout << "No se seleccionó ninguna operación válida." << std::endl;
    }
    // if (opcion != 't' || opcion != 'h') {
    // } else
    //   break;
    if (opcion == 'd' && a2 == 0) {
      std::cout << "---No se puede dividir por cero---" << std::endl;
      continue;
    }
    // Create a client and connect to the server at hostname:port
    XmlRpcClient client(hostname, port);

    XmlRpcValue noArgs, emptyArgs, result;

    noArgs[0] = a1;
    noArgs[1] = a2;
    if (opcion == 'a' || opcion == 's' || opcion == 'm' || opcion == 'd' ||
        opcion == 'p' || opcion == 'r' || opcion == 'h') {
      if (opcion == 'a')
        client.execute("sum", noArgs, result);
      if (opcion == 's')
        client.execute("res", noArgs, result);
      if (opcion == 'm')
        client.execute("mul", noArgs, result);
      if (opcion == 'd')
        client.execute("div", noArgs, result);
      if (opcion == 'p')
        client.execute("pow", noArgs, result);
      if (opcion == 'r')
        client.execute("nroot", noArgs, result);
      if (opcion == 'h')
        client.execute("history", emptyArgs, result);
      std::cout << result << std::endl << std::endl;
    }
  }
}
