#include <iostream>
#include <string>
#include "cliente.h"
#include "boleto.h"
using namespace std;

//Cliente//

//Constructor parametrizado
Cliente::Cliente(string _nombre, string _correo, int _telefono)
{
    nombre = _nombre;
    correo = _correo;
    telefono = _telefono;
}

//Sobrecarga del constructor - sobrecarga  
Cliente::Cliente(string _nombre)
{
    nombre = _nombre;
    correo = "";
    telefono = 0;
}

//Sobrecarga de constructor   
Cliente::Cliente()
{
    nombre = "";
    correo = "";
    telefono = 0;
}


void Cliente::setNombre(string _nombre)
{
    nombre = _nombre;
}
string Cliente::getNombre()
{
    return nombre;
}



void Cliente::setCorreo(string _correo)
{
    correo = _correo;
}
string Cliente::getCorreo()
{
    return correo;
}



void Cliente::setTelefono(int _telefono)
{
    telefono = _telefono;
}
int Cliente::getTelefono()
{
    return telefono;
}


//otros metodos
void Cliente::comprarBoleto(Boleto b)
{
    b.generar_boleto();
}

void Cliente::comprarBoleto(Boleto boletos[], int cantidad)//Sobrecarga
{
    for (int i = 0; i < cantidad; i++) {
        boletos[i].generar_boleto();
    }
}

