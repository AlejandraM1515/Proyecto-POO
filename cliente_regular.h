#ifndef CLIENTE_REGULAR_H
#define CLIENTE_REGULAR_H
#include <string>
#include "cliente.h"
using namespace std;

//Clase Cliente regular//
class Cliente_regular : public Cliente { //herencia de cliente
private:
    int puntos_fidelidad;
public:
    //Metodo constructor
    Cliente_regular(); //Constructor por default
    Cliente_regular(string, string, int, int); //Constructor por parametros
    //Get y Set
    void setPuntos_fidelidad(int);
    int getPuntos_fidelidad();
    //otros metodos
    virtual void info_cliente(); //Polimorfismo 
    virtual void mostrar_precio();
    virtual float get_precio_unitario();

    void precio_boleto();
    void precio_boleto(int cantidad); // Sobrecarga del metodo: Recibe la cantidad de boletos que se desea comprar para mostrar la cliente cunato pagara
};

#endif // CLIENTE_REGULAR_H