 #include "lata.hpp"
 #include "cospel.hpp"
 #include "orden.hpp"
 #include "string"

using namespace std;
 
class Expendedora {
    Lata stock[];
    Cospel cospelesRestantes[];
    int latasRestantes;
    bool estado;
    Orden registroOrdenes[];
    Orden orden;
    void habilitarBotones(Orden orden, bool estado);
    Orden nuevaOrden(void);
    bool procesarOrden(void);
    bool aceptarCospel(Cospel cospel);
    bool cobrarCospel(void);
    bool actualizarStock(Bebida bebida);
    Cospel* vuelto(void);
    void restablecerContadores(void);
    void alertaError();
};