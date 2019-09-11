#include "expendedora.hpp"

void habilitarBotones(Orden orden, bool estado);
Orden nuevaOrden(void);
bool procesarOrden(void);
bool aceptarCospel(Cospel cospel);
bool cobrarCospel(void);
bool actualizarStock(Bebida bebida);
Cospel* vuelto(void);
void restablecerContadores(void);
void alertaError();