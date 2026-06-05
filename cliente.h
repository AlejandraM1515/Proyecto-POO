#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "boleto.h"
using namespace std;


// Clase cliente - clase abstracta
class Cliente {
private:
    string nombre;
    string correo;
    int telefono;
public:
    //Metodo constructor
    Cliente();
    Cliente(string, string, int);
    Cliente(string); //Sobrecarga
    //Get y Set
    void setNombre(string);
    string getNombre();
    void setCorreo(string);
    string getCorreo();
    void setTelefono(int);
    int getTelefono();
    //otros metodos
    void comprarBoleto(Boleto b);
    void comprarBoleto(Boleto boletos[], int cantidad); // Sobrecarga del metodo: Recibe un arreglo de boletos y la cantidad total comprada, para ucando el cliente hace varias compras
    
    //polimorfismo
    virtual void info_cliente() = 0; //clase abstracta
    virtual void mostrar_precio() = 0;
    virtual float get_precio_unitario() = 0;

    virtual ~Cliente() {} //Destructor virtual
};

#endif // CLIENTE_H
