#include <iostream>
#include <string>
#include "boleto.h"


using namespace std;

//Clase Boleto//

//constructor por default
Boleto::Boleto()
{
    num_boleto = 0;
    hora = "";
    pelicula = "";
    asciento = "";
    precio = 0;
    tipo_cliente = "";
}

//COnstructor por parametros - sobrecarga del constructor
Boleto::Boleto(int _num_boleto, string _hora, string _pelicula, string _asciento, float _precio, string _tipo_cliente, Funcion f)
{
    num_boleto = _num_boleto;
    hora = _hora;
    pelicula = _pelicula;
    asciento = _asciento;
    precio = _precio;
    tipo_cliente = _tipo_cliente;
    funcion = f; //composicion
}

//Getter y Setters
void Boleto::setNum_boleto(int _num_boleto)
{
    num_boleto = _num_boleto;
}
int Boleto::getNum_boleto()
{
    return num_boleto;
}


void Boleto::setHora(string _hora)
{
    hora = _hora;
}
string Boleto::getHora()
{
    return hora;
}


void Boleto::setPelicula(string _pelicula)
{
    pelicula = _pelicula;
}
string Boleto::getPelicula()
{
    return pelicula;
}


void Boleto::setAsiento(string _asciento)
{
    asciento = _asciento;
}
string Boleto::getAsiento()
{
    return asciento;
}


void Boleto::setPrecio(float _precio)
{
    precio = _precio;
}
float Boleto::getPrecio()
{
    return precio;
}


void Boleto::setTipo_cliente(string _tipo_cliente)
{
    tipo_cliente = _tipo_cliente;
}
string Boleto::getTipo_cliente()
{
    return tipo_cliente;
}


//otros metodos
void Boleto::generar_boleto()
{
    cout << "BOLETO:" << endl;
    cout << "Numero de boleto: " << num_boleto << endl;
    cout << "Pelicula: " << pelicula << endl;
    cout << "Hora: " << hora << endl;
    cout << "Asiento: " << asciento << endl;
    cout << "Tipo de cliente: " << tipo_cliente << endl;
    cout << "Precio: $" << precio << endl;
    cout << "-" << endl;
}

/*sobrecarga del metodo generar boleto para mostrar un resumen 
del boleto cuando se compran varios boletos sin repetir tanta info*/
void Boleto::generar_boleto(bool resumido)//Sobrecarga
{
    if (resumido) {
        cout << "Boleto #" << num_boleto <<endl;
        cout << " | " << pelicula <<endl;
        cout << " | Asiento: " << asciento << endl;
        cout << " | $" << precio <<endl;
    } else {
            cout << "BOLETO:" << endl;
            cout << "Numero de boleto: " << num_boleto << endl;
            cout << "Pelicula: " << pelicula << endl;
            cout << "Hora: " << hora << endl;
            cout << "Asiento: " << asciento << endl;
            cout << "Tipo de cliente: " << tipo_cliente << endl;
            cout << "Precio: $" << precio << endl;
            cout << "-" << endl;        
    }
}
