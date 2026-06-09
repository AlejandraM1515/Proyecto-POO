#include <iostream>
#include "caja.h"
using namespace std;

//Caja//

//constructor
Caja::Caja() {
    totalClientes = 0;
    totalBoletos  = 0;
    for (int i = 0; i < 100; i++) {
        clientes[i] = nullptr;
        boletos[i]  = nullptr;
    }
}

//otros metodos
void Caja::registrarCliente(Cliente* c) {
    if (totalClientes < 100)
        clientes[totalClientes++] = c;
}

void Caja::registrarBoleto(Boleto* b) {
    if (totalBoletos < 100)
        boletos[totalBoletos++] = b;
}

void Caja::verBoletos() {
    cout << "Registro de boletos:" << endl;
    if (totalBoletos == 0) {
        cout << "No hay boletos registrados aun." << endl;
    } else {
        for (int i = 0; i < totalBoletos; i++) {
            boletos[i]->generar_boleto();
        }
    }
    cout << endl;
}

void Caja::verClientes() {
    cout << "Clientes registrados" << endl;
    if (totalClientes == 0) {
        cout << "No hay clientes registrados aun." << endl;
    } else {
        for (int i = 0; i < totalClientes; i++) {
            cout << "--- Cliente #" << i + 1 << " ---" << endl;
            clientes[i]->info_cliente(); //Polimorfismo
            cout << endl;
        }
    }
}

bool Caja::iniciar_compra() {
    int opcion;
    do {
        cout << "Sistema CineCo - Caja:" << endl;
        cout << "1. Ver registro de boletos" << endl;
        cout << "2. Ver clientes registrados" << endl;
        cout << "3. Nueva compra" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: verBoletos();  break;
            case 2: verClientes(); break;
            case 3: return true;   // Continua al main para ejecutar la compra
            case 0: cout << "Cerrando sistema. Hasta luego!" << endl;
                    return false;  // Le avisa al main que debe salir
            default: cout << "Opcion invalida." << endl << endl;
        }
    } while (opcion != 0);

    return false;
}