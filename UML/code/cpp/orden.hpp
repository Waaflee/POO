#include "lata.hpp"

class Orden {
    Lata pedido[];
    int costo;
    string timeStamp;
    bool éxito;
    string detalleError;
    Lata solicitarLata(Lata lata);
    void imprimirDetalle(Orden ordenes[]);
    void imprimirResumen(Orden ordenes[]);
};