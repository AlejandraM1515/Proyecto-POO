#include <iostream>
#include <string>
#include "sala.h"

using namespace std;

//Sala//

//constructor por defautl
Sala::Sala()
{
    id_sala = 0;
    tipo_sala = "";
    asiento = 0;
    filas = 6;
    columnas = 8;
    generarAsientos();
}

//Constructor por parametros - sobrecarga dle constructor
Sala::Sala(int _id_sala, string _tipo_sala, int _asiento)
{
    id_sala = _id_sala;
    tipo_sala = _tipo_sala;
    asiento = _asiento;

    if (tipo_sala == "junior") {
        filas = 5;
        columnas = 6;
    } else if (tipo_sala == "MACRO XE") {
        filas = 8;
        columnas = 10;
    } else {
        filas = 6;
        columnas = 8;
    }

    generarAsientos();
}

//Getter y Setters
void Sala::setId_sala(int _id_sala)
{
    id_sala = _id_sala;
}
int Sala::getId_sala()
{
    return id_sala;
}



void Sala::setTipo_sala(string _tipo_sala)
{
    tipo_sala = _tipo_sala;
}
string Sala::getTipo_sala()
{
    return tipo_sala;
}


void Sala::setAsiento(int _asiento)
{
    asiento = _asiento;
}
int Sala::getAsiento()
{
    return asiento;
}


//otros metodos
void Sala::generarAsientos()
{
    char letra = 'A';
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizAsientos[i][j] = string(1, letra) + to_string(j + 1);
            ocupado[i][j] = false;
        }
        letra++;
    }
}

void Sala::mostrarSala()
{
    cout << "Pantalla" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (ocupado[i][j])
                cout << "[XX] ";
            else
                cout << "[" << matrizAsientos[i][j] << "] ";
        }
        cout << endl;
    }
    cout << "-" << endl;
}

void Sala::verificar_disponibilidad()
{
    int libres = 0;
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            if (!ocupado[i][j]) libres++;
    cout << "Asientos disponibles: " << libres << endl;
}

bool Sala::reservar(string asientoUser)
{
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matrizAsientos[i][j] == asientoUser) {
                if (ocupado[i][j]) return false;
                ocupado[i][j] = true;
                return true;
            }
        }
    }
    return false;
}

