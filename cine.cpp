#include <iostream>
#include <string>
#include "cine.h"

using namespace std;


//Pelicula//

//constructor
Pelicula::Pelicula()
{
    id_pelicula = 0;
    titulo = "";
    genero = "";
    duracion = 0;
    clasificacion = "";
}

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




//Sala//

//constructor
Sala::Sala()
{
    id_sala = 0;
    tipo_sala = "";
    asiento = 0;
    filas = 6;
    columnas = 8;
    generarAsientos();
}

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




//Boleto//

//constructor
Boleto::Boleto()
{
    num_boleto = 0;
    hora = "";
    pelicula = "";
    asciento = "";
    precio = 0;
    tipo_cliente = "";
}

Boleto::Boleto(int _num_boleto, string _hora, string _pelicula, string _asciento, float _precio, string _tipo_cliente, Funcion f)
{
    num_boleto = _num_boleto;
    hora = _hora;
    pelicula = _pelicula;
    asciento = _asciento;
    precio = _precio;
    tipo_cliente = _tipo_cliente;
    funcion = f;
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




//Cliente//

//Constructor parametrizado
Cliente::Cliente(int _id, string _nombre, string _correo, int _telefono)
{
    id = _id;
    nombre = _nombre;
    correo = _correo;
    telefono = _telefono;
}

//Sobrecarga del constructor
Cliente::Cliente(int _id, string _nombre)
{
    id = _id;
    nombre = _nombre;
    correo = "";
    telefono = 0;
}

Cliente::Cliente()
{
    id = 0;
    nombre = "";
    correo = "";
    telefono = 0;
}

//Getter y Setters
void Cliente::setId(int _id)
{
    id = _id;
}
int Cliente::getId()
{
    return id;
}



void Cliente::setNombre(string _nombre)
{
    nombre = _nombre;
}
string Cliente::getNombre()
{
    return nombre;
}



void Cliente::setCorreo(string _correo)
{
    correo = _correo;
}
string Cliente::getCorreo()
{
    return correo;
}



void Cliente::setTelefono(int _telefono)
{
    telefono = _telefono;
}
int Cliente::getTelefono()
{
    return telefono;
}


//otros metodos
void Cliente::comprarBoleto(Boleto b)
{
    b.generar_boleto();
}

void Cliente::info_cliente()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Correo: " << correo << endl;
    cout << "Telefono: " << telefono << endl;
}




//Cliente regular//

//constructor
Cliente_regular::Cliente_regular()
    : Cliente()
{
    puntos_fidelidad = 0;
}

Cliente_regular::Cliente_regular(int _id, string _nombre, string _correo, int _telefono, int _puntos_fidelidad)
    : Cliente(_id, _nombre, _correo, _telefono)
{
    puntos_fidelidad = _puntos_fidelidad;
}

//Getter y Setters
void Cliente_regular::setPuntos_fidelidad(int _puntos_fidelidad)
{
    puntos_fidelidad = _puntos_fidelidad;
}
int Cliente_regular::getPuntos_fidelidad()
{
    return puntos_fidelidad;
}


//otros metodos
void Cliente_regular::precio_boleto()
{
    cout << "Precio del boleto: $90.00" << endl;
    cout << "Tus puntos de fidelidad: " << puntos_fidelidad << endl;
}




//Cliente VIP//

//constructor
Cliente_vip::Cliente_vip()
    : Cliente()
{
    beneficios = "";
}

Cliente_vip::Cliente_vip(int _id, string _nombre, string _correo, int _telefono, string _beneficios)
    : Cliente(_id, _nombre, _correo, _telefono)
{
    beneficios = _beneficios;
}

//Getter y Setters
void Cliente_vip::setBeneficios(string _beneficios)
{
    beneficios = _beneficios;
}
string Cliente_vip::getBeneficios()
{
    return beneficios;
}


//otros metodos
double Cliente_vip::calcular_descuento()
{
    return 90.0 * 0.20;
}

void Cliente_vip::precio_boleto_descuento()
{
    double descuento = calcular_descuento();
    double precio_final = 90.0 - descuento;
    cout << "Precio con descuento VIP (20%): $" << precio_final << endl;
    cout << "Beneficios: " << beneficios << endl;
}
