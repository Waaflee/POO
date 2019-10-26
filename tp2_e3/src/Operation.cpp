#include "../include/Operation.hpp"
Operation::Operation(double op1, double op2, std::string operand){
    this->operando1 = op1;
    this->operando2 = op2;
    this->operador = operand;
}
Operation::~Operation(){

}
std::string Operation::toString(){
    return(std::string(operando1)+" "+operador+" "+std::string(operando2));
}