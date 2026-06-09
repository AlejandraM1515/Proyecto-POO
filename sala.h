#ifndef SALA_H
#define SALA_H
#include <string>
using namespace std;

// Clase Sala
class Sala {
private:
    int id_sala;
    string tipo_sala;
    int asiento;
    string matrizAsientos[20][20];
    bool ocupado[20][20];
    int filas;
    int columnas;
public:
    //Metodo constructor
    Sala(); //Constructor por default
    Sala(int, string, int); //Constructor por parametros
    //Get y Set
    void setId_sala(int);
    int getId_sala();
    void setTipo_sala(string);
    string getTipo_sala();
    void setAsiento(int);
    int getAsiento();
    //otros metodos
    void generarAsientos();
    void mostrarSala();
    void verificar_disponibilidad();
    bool reservar(string);
};

#endif // SALA_H