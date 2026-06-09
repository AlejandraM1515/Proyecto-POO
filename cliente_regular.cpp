#include <iostream>
#include <string>
#include "cliente_regular.h"

using namespace std;



//Clase Cliente regular//

//constructor por default
Cliente_regular::Cliente_regular() 
    : Cliente()
{
    puntos_fidelidad = 0;
}

//Constructor por parametros
Cliente_regular::Cliente_regular(string _nombre, string _correo, int _telefono, int _puntos_fidelidad)
    : Cliente(_nombre, _correo, _telefono)
{
    puntos_fidelidad = _puntos_fidelidad;
}

//Getter y Setters
void Cliente_regular::setPuntos_fidelidad(int _puntos_fidelidad)
{
    puntos_fidelidad = _puntos_fidelidad;
}
int Cliente_regular::getPuntos_fidelidad()
{
    return puntos_fidelidad;
}


//otros metodos
//Como en cliente es una clase abstracta, se deben implementar los metodos virtuales puros para poder crear objetos de esta clase
void Cliente_regular::info_cliente() {
    cout << "Nombre: " << getNombre() << endl;
    cout << "Correo: " << getCorreo() << endl;
    cout << "Telefono: " << getTelefono() << endl;
    cout << "Tipo: Regular" << endl;
    cout << "Puntos de fidelidad: " << puntos_fidelidad << endl;
}

void Cliente_regular::mostrar_precio() {
    cout << "Precio del boleto: $90.00" << endl;
    cout << "Tus puntos de fideliad: " << puntos_fidelidad << endl;
}

//Sobreescritura  
float Cliente_regular::get_precio_unitario() {
    return 90.0f;
}

void Cliente_regular::precio_boleto()
{
    cout << "Precio del boleto: $90.00" << endl;
    cout << "Tus puntos de fidelidad: " << puntos_fidelidad << endl;
}

//Sobreescritura
void Cliente_regular::precio_boleto(int cantidad) //Sobrecarga
{
    float total = 90.0f* cantidad;
    cout << "Boletos seleccionados: " << cantidad << endl;
    cout << "Precio unitario: $90.00" << endl;
    cout << "Total a pagar: $" << total << endl;
    cout << "Puntos de fidelidad: " << getPuntos_fidelidad() << endl;
}
                                          

