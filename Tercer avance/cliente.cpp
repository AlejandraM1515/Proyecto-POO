#include <iostream>
#include <string>
#include "cliente.h"
#include "boleto.h"
using namespace std;

//Cliente//

//Constructor parametrizado
Cliente::Cliente(int _id, string _nombre, string _correo, int _telefono)
{
    id = _id;
    nombre = _nombre;
    correo = _correo;
    telefono = _telefono;
}

//Sobrecarga del constructor
Cliente::Cliente(int _id, string _nombre)
{
    id = _id;
    nombre = _nombre;
    correo = "";
    telefono = 0;
}

Cliente::Cliente()
{
    id = 0;
    nombre = "";
    correo = "";
    telefono = 0;
}

//Getter y Setters
void Cliente::setId(int _id)
{
    id = _id;
}
int Cliente::getId()
{
    return id;
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

void Cliente::comprarBoleto(Boleto boletos[], int cantidad)//Sobrecarrga
{
    for (int i = 0; i < cantidad; i++) {
        boletos[i].generar_boleto();
    }
}

void Cliente::info_cliente()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Correo: " << correo << endl;
    cout << "Telefono: " << telefono << endl;
}

void Cliente::mostrar_precio() {
    cout << "Precio base: $90.00" << endl;
}

float Cliente::get_precio_unitario() {
    return 90.0f;
}
