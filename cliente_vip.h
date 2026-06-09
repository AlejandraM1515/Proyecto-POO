#ifndef CLIENTE_VIP_H
#define CLIENTE_VIP_H
#include <string>
#include "cliente.h"
using namespace std;

//Clase Cliente VIP//
class Cliente_vip : public Cliente {
private:
    string beneficios;
public:
    //Metodo constructor
    Cliente_vip(); //Constructor por default
    Cliente_vip(string, string, int, string);
    //Get y Set
    void setBeneficios(string);
    string getBeneficios();
    //otros metodos
    //Polimorfismo, implementando los metodos abstractos de cliente
    virtual void info_cliente();
    virtual void mostrar_precio();
    virtual float get_precio_unitario();

    
    double calcular_descuento();
    void precio_boleto_descuento();
    void precio_boleto_descuento(int cantidad); //Sobrecarga del metodo: Recibe la cantidad de boletos uqe se desea comprar para mostrar la cliente cunato pagara aplicando el descuento
};

#endif // CLIENTE_VIP_H