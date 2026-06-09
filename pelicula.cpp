#include <iostream>
#include <string>
#include "pelicula.h"


using namespace std;


//Pelicula//

//constructor por default
Pelicula::Pelicula()
{
    id_pelicula = 0;
    titulo = "";
    genero = "";
    duracion = 0;
    clasificacion = "";
}

//Constructor por parametros
Pelicula::Pelicula(int _id_pelicula, string _titulo, string _genero, int _duracion, string _clasificacion)
{
    id_pelicula = _id_pelicula;
    titulo = _titulo;
    genero = _genero;
    duracion = _duracion;
    clasificacion = _clasificacion;
}

//Getter y Setters
void Pelicula::setId_pelicula(int _id_pelicula)
{
    id_pelicula = _id_pelicula;
}
int Pelicula::getId_pelicula()
{
    return id_pelicula;
}


void Pelicula::setTitulo(string _titulo)
{
    titulo = _titulo;
}
string Pelicula::getTitulo()
{
    return titulo;
}



void Pelicula::setGenero(string _genero)
{
    genero = _genero;
}
string Pelicula::getGenero()
{
    return genero;
}


void Pelicula::setDuracion(int _duracion)
{
    duracion = _duracion;
}
int Pelicula::getDuracion()
{
    return duracion;
}


void Pelicula::setClasificacion(string _clasificacion)
{
    clasificacion = _clasificacion;
}
string Pelicula::getClasificacion()
{
    return clasificacion;
}


//otros metodos
void Pelicula::info_pelicula()
{
    cout << "Titulo: " << titulo << endl;
    cout << "Genero: " << genero << endl;
    cout << "Duracion: " << duracion << " minutos" << endl;
    cout << "Clasificacion: " << clasificacion << endl;
}

void Pelicula::info_pelicula(bool resumida)//sobrecarga
{
    if(resumida){
        cout << "Titulo: " << titulo
             << ", Clasificacion: " <<clasificacion << endl;
    } else {
    cout << "Titulo: " << titulo << endl;
    cout << "Genero: " << genero << endl;
    cout << "Duracion: " << duracion << " minutos" << endl;
    cout << "Clasificacion: " << clasificacion << endl;        
    }
}