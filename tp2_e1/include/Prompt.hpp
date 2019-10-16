#pragma once
#include "string"

#include "Trayectoria.hpp"

class Prompt {
    private:
        Trayectoria robot;
    public:
        Prompt();
        ~Prompt();
        bool validarOrden(std::string orden);

};