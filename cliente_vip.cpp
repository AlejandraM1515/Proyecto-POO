#include <iostream>
#include <string>
#include "cliente_vip.h"

using namespace std;


//Clase Cliente VIP//

//constructor
Cliente_vip::Cliente_vip() //Herencia
    : Cliente()
{
    beneficios = "";
}

//Constructor por parametros
Cliente_vip::Cliente_vip(string _nombre, string _correo, int _telefono, string _beneficios)
    : Cliente(_nombre, _correo, _telefono)
{
    beneficios = _beneficios;
}

//Getter y Setters
void Cliente_vip::setBeneficios(string _beneficios)
{
    beneficios = _beneficios;
}
string Cliente_vip::getBeneficios()
{
    return beneficios;
}


//otros metodos
double Cliente_vip::calcular_descuento()
{
    return 90.0 * 0.20;
}

void Cliente_vip::info_cliente() {
    cout << "Nombre: " << getNombre() << endl;
    cout << "Correo: " << getCorreo() << endl;
    cout << "Telefono: " << getTelefono() << endl;
    cout << "Tipo: VIP" << endl;
    cout << "Beneficios: " << beneficios << endl;
}

void Cliente_vip::mostrar_precio() {
    double descuento = calcular_descuento();
    double precio_final = 90.0 - descuento;
    cout << "Precio con descuento VIP (20%): $" << precio_final << endl;
    cout << "Beneficios: " << beneficios << endl;
    
}

float Cliente_vip::get_precio_unitario() {
    return static_cast<float>(90.0 - calcular_descuento());
}

void Cliente_vip::precio_boleto_descuento()
{
    double descuento = calcular_descuento();
    double precio_final = 90.0 - descuento;
    cout << "Precio con descuento VIP (20%): $" << precio_final << endl;
    cout << "Beneficios: " << beneficios << endl;
}

void Cliente_vip::precio_boleto_descuento(int cantidad)
{
    double precio_unitario = 90.0 - calcular_descuento();
    double total = precio_unitario * cantidad;
    cout << "Boletos seleccionados: " << cantidad << endl;
    cout << "Precio c/descuento: $" << precio_unitario << "c/u" << endl;
    cout << "Total a pagar: $" << total << endl;
    cout << "Beneficios incluidos: " << getBeneficios() << endl;
}
