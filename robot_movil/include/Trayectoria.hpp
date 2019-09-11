#pragma once
#include "list"

#define AVANCE 4.25
enum Movement {COMENZAR, PARAR, REPORTE, IZQUIERDA, DERECHA, AVANZAR, RETROCEDER, GIRAR};

class Trayectoria {

    private:
        Movement ordenActual;
        std::list<Movement> Ordenes;
        float distanciaTotal;
        float tiempoTotal;
        float tiempoInicial;

    public:
        Trayectoria();
        ~Trayectoria();
        void setTiempoInicial(float tiempoInicial) {
            this->tiempoInicial = tiempoInicial;
        }
        
        float getTiempoInicial() {
            return tiempoInicial;
        }
        
        void setTiempoTotal(float tiempoTotal) {
            this->tiempoTotal = tiempoTotal;
        }
        
        float getTiempoTotal() {
            return tiempoTotal;
        }
        
        void setDistanciaTotal(float distanciaTotal) {
            this->distanciaTotal = distanciaTotal;
        }
        
        float getDistanciaTotal() {
            return distanciaTotal;
        }
        void setOrdenActual(Movement ordenActual) {
            this->ordenActual = ordenActual;
        }
        
        Movement getOrdenActual() {
            return ordenActual;
        }
        
};