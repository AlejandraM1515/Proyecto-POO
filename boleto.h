#ifndef BOLETO_H
#define BOLETO_H
#include <string>
#include "funcion.h"
using namespace std;

// Clase boleto //
class Boleto {
private:
    int num_boleto;
    string hora;
    string pelicula;
    string asciento;
    float precio;
    string tipo_cliente;
    Funcion funcion; //Composicion
public:
    //Metodo constructor
    Boleto(); //Constructor por dafault
    Boleto(int, string, string, string, float, string, Funcion); //Constructor por parametros
    //Get y Set
    void setNum_boleto(int);
    int getNum_boleto();
    void setHora(string);
    string getHora();
    void setPelicula(string);
    string getPelicula();
    void setAsiento(string);
    string getAsiento();
    void setPrecio(float);
    float getPrecio();
    void setTipo_cliente(string);
    string getTipo_cliente();
    //otros metodos
    void generar_boleto();
    void generar_boleto(bool resumido); // Sobrecarga del metodo: para mostrar un resumen cuando se ocmpran muchos boletos sin repetir tanta info
};

#endif // BOLETO_H