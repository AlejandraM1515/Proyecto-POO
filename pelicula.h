#ifndef PELICULA_H
#define PELICULA_H
#include <string>
using namespace std;


// Clase Pelicula
class Pelicula {
private:
    int id_pelicula;
    string titulo;
    string genero;
    int duracion;
    string clasificacion;
public:
    //SObrecarga del constructor
    Pelicula(); //Constructor por default
    Pelicula(int, string, string, int, string); //Constructor por parametros
    //Get y Set
    void setId_pelicula(int);
    int getId_pelicula();
    void setTitulo(string);
    string getTitulo();
    void setGenero(string);
    string getGenero();
    void setDuracion(int);
    int getDuracion();
    void setClasificacion(string);
    string getClasificacion();
    //otros metodos
    void info_pelicula();
    void info_pelicula(bool resumida); //Sobrecarga del metodo - Para mostrar las peliculas y no saturar la usairo de info
};

#endif // PELICULA_H