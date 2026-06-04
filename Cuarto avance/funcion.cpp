#include <iostream>
#include <string>
#include "funcion.h"

using namespace std;

//Funcion//

//constructor
Funcion::Funcion()
{
    fecha = "";
    hora = "";
    clasificacion = "";
}

Funcion::Funcion(string _fecha, string _hora, string _clasificacion, Pelicula p, Sala s)
{
    fecha = _fecha;
    hora = _hora;
    clasificacion = _clasificacion;
    pelicula = p;
    sala = s;
}

//Getter y Setters
void Funcion::setFecha(string _fecha)
{
    fecha = _fecha;
}
string Funcion::getFecha()
{
    return fecha;
}


void Funcion::setHora(string _hora)
{
    hora = _hora;
}
string Funcion::getHora()
{
    return hora;
}


void Funcion::setClasificacion(string _clasificacion)
{
    clasificacion = _clasificacion;
}
string Funcion::getClasificacion()
{
    return clasificacion;
}


//Composicion
void Funcion::setPelicula(Pelicula p)
{
    pelicula = p;
}
Pelicula Funcion::getPelicula() const
{
    return pelicula;
}


void Funcion::setSala(Sala s)
{
    sala = s;
}
Sala Funcion::getSala() const
{
    return sala;
}


//otros metodos
void Funcion::reservacion()
{
    cout << "Funcion: " << pelicula.getTitulo() << " | Hora: " << hora << " | Sala: " << sala.getTipo_sala() << endl;
}

void Funcion::disponibilidad()
{
    sala.verificar_disponibilidad();
}
