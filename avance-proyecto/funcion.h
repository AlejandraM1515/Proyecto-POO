#ifndef FUNCION_H
#define FUNCION_H
#include <string>
#include "pelicula.h"
#include "sala.h"
using namespace std;

// Clase Funcion
class Funcion {
private:
    string fecha;
    string hora;
    string clasificacion;
    Pelicula pelicula;  //Composicion
    Sala sala; //Composicion
public:
    //Metodo constructor
    Funcion();
    Funcion(string, string, string, Pelicula, Sala);
    //Get y Set
    void setFecha(string);
    string getFecha();
    void setHora(string);
    string getHora();
    void setClasificacion(string);
    string getClasificacion();
    Pelicula getPelicula() const;
    void setPelicula(Pelicula p);
    Sala getSala() const;
    void setSala(Sala s);
    //otros metodos
    void reservacion();
    void disponibilidad();
};

#endif // FUNCION_H