#ifndef CAJA_H
#define CAJA_H
#include "cliente.h"
#include "boleto.h"
using namespace std;

// Clase Caja
class Caja {
private:
    Cliente* clientes[100]; //Se usa un puntero a cliente, para maximo 100 clientes  
    Boleto*  boletos[100]; //Se usa un puntero a boleto, para maximo 100 boletos   
    int totalClientes;
    int totalBoletos;

public:
    //Metodo constructor por default
    Caja();
    //otros metodos
    bool iniciar_compra();
    void verBoletos();
    void verClientes();
    void registrarCliente(Cliente* c);
    void registrarBoleto(Boleto* b);
};

#endif // CAJA_H
    
