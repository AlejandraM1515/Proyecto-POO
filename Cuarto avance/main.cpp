#include <iostream>
#include <string>
#include "pelicula.h"
#include "funcion.h"
#include "boleto.h"
#include "cliente.h"
#include "cliente_regular.h"
#include "cliente_vip.h"

using namespace std;


int main() {

    cout << "Bienvenido a CineCo!" << endl;
    cout << endl;
    cout << "A continuacion podra hacer su reservacion" << endl;
    cout << endl;


    //Datos del cliente
    string id_cliente;
    string nombre_cliente, correo_cliente;
    int telefono_cliente;

   
    cout << "Ingrese su nombre: ";
    getline(cin, nombre_cliente);
    cout << "Ingrese su correo: ";
    getline(cin, correo_cliente);
    cout << "Ingrese su telefono: ";
    cin >> telefono_cliente;
    cin.ignore(); 
    cout << endl;       


    //Tipo de cliente
    int tipo_cli;
    cout << "Seleccione su tipo de cliente:" << endl;
    cout << "1. Cliente Regular" << endl;
    cout << "2. Cliente VIP" << endl;
    cout << "Opcion: ";
    cin >> tipo_cli;
    cout << endl;


    //Polimorfismo
    Cliente *cliente = nullptr;  

    if (tipo_cli == 1){
    cliente = new Cliente_regular(nombre_cliente, correo_cliente, telefono_cliente, 0);
    } else {
    cliente = new Cliente_vip(nombre_cliente, correo_cliente, telefono_cliente, "Palomitas gratis + Refresco");
    }


    cliente->mostrar_precio();
    cout << endl;
    cout << "Hola " << cliente->getNombre() << "!" << endl;
    cout << endl;

    float precio_unitario = cliente->get_precio_unitario();
    

    //Seleciona la pelicula
    int opPelicula;
    cout << "Seleccione la pelicula que desea ver:" << endl;
    cout << "1. Zootopia 2 | AA | 108 min" << endl;
    cout << "2. Wicked: Por siempre | A | 138 min" << endl;
    cout << "Opcion: ";
    cin >> opPelicula;
    cout << endl;

    if (opPelicula < 1 || opPelicula > 2) {
        cout << "Opcion invalida" << endl;
        return 0;
    }

    Pelicula peli;
    Funcion funciones[10];
    int totalFunciones = 0;


    //Segun la pelicula elegida se configuran las funciones disponibles
    if (opPelicula == 1) {
        peli = Pelicula(1, "Zootopia 2", "Animacion", 108, "AA");

        Sala s1(1, "tradicional", 48);
        Sala s2(2, "junior", 30);
        Sala s3(3, "MACRO XE", 80);

        funciones[totalFunciones++] = Funcion("2026-05-21", "12:00 p.m", "AA", peli, s1);
        funciones[totalFunciones++] = Funcion("2026-05-21", "3:30 p.m",  "AA", peli, s2);
        funciones[totalFunciones++] = Funcion("2026-05-21", "7:00 p.m",  "AA", peli, s3);

    } else {
        peli = Pelicula(2, "Wicked: Por siempre", "Musical", 138, "A");

        Sala s1(1, "tradicional", 48);
        Sala s2(2, "tradicional", 48);
        Sala s3(3, "tradicional", 48);

        funciones[totalFunciones++] = Funcion("2026-05-21", "1:55 p.m", "A", peli, s1);
        funciones[totalFunciones++] = Funcion("2026-05-21", "4:45 p.m", "A", peli, s2);
        funciones[totalFunciones++] = Funcion("2026-05-21", "8:00 p.m", "A", peli, s3);
    }


    // Muestra informacion de la pelicula seleccionada
    cout << "Informacion de la pelicula:" << endl;
    peli.info_pelicula();
    cout << endl;


    //Se muestran los horarios disponibles
    cout << "Horarios disponibles:" << endl;
    for (int i = 0; i < totalFunciones; i++) {
        cout << i + 1 << ") " << funciones[i].getHora()
             << " | Sala: " << funciones[i].getSala().getTipo_sala() << endl;
    }

    //El usuario elige el horario
    int opHorario;
    cout << "Seleccione un horario: ";
    cin >> opHorario;
    cout << endl;

    if (opHorario < 1 || opHorario > totalFunciones) {
        cout << "Opcion invalida" << endl;
        return 0;
    }

    Funcion seleccion = funciones[opHorario - 1];
    Sala sala = seleccion.getSala();


    //Se escoge el numero de boletos
    int boletos_cantidad;
    cout << "Cuantos boletos desea? ";
    cin >> boletos_cantidad;
    cout << endl;

    sala.mostrarSala();
    cout << endl;

    string asientos_elegidos[10];
    for (int i = 0; i < boletos_cantidad; i++) {
        //El usuario elige el asiento y si esta ocupado debera seleccionar otro
        cout << "Seleccione asiento " << i + 1 << ": ";
        cin >> asientos_elegidos[i];

        if (!sala.reservar(asientos_elegidos[i])) {
            cout << "Asiento ocupado. Intenta seleccionar otro asiento" << endl;
            i--;
        } else {
            cout << endl;
            sala.mostrarSala();
            cout << endl;
        }
    }


    //Se generan los boletos
    cout << endl;
    cout << "Reserva completada!" << endl;
    cout << endl;


    for (int i = 0; i < boletos_cantidad; i++) {
        Boleto b(i + 1, seleccion.getHora(), peli.getTitulo(), asientos_elegidos[i], precio_unitario, (tipo_cli == 1? "Regular" : "VIP"), seleccion);
        cliente ->comprarBoleto(b);
    }

    cout << endl;
    cout << "Informacion del cliente:" << endl;

    cliente->info_cliente();
    cout << "Total pagado: $" << precio_unitario * boletos_cantidad << endl;

    delete cliente;

    return 0;
    }
