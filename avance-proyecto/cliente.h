#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "boleto.h"
using namespace std;


// Clase cliente
class Cliente {
private:
    int id;
    string nombre;
    string correo;
    int telefono;
public:
    //Metodo constructor
    Cliente();
    Cliente(int, string, string, int);
    Cliente(int, string); //Sobrecarga
    //Get y Set
    void setId(int);
    int getId();
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
    virtual void info_cliente();
    virtual void mostrar_precio();
    virtual float get_precio_unitario();
    virtual ~Cliente() {} //Destructor virtual
};

#endif // CLIENTE_H
