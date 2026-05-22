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
    //Metodo constructor
    Pelicula();
    Pelicula(int, string, string, int, string);
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
};


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
    Sala();
    Sala(int, string, int);
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


/* Clase boleto*/
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
    Boleto();
    Boleto(int, string, string, string, float, string, Funcion);
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
};


// Clase cliente
class Cliente {
private:
    int id;
    string nombre;
    string correo;
    int telefono;
public:
    //Metodo constructor
    Cliente();
    Cliente(int, string, string, int);
    Cliente(int, string); //Sobrecarga
    //Get y Set
    void setId(int);
    int getId();
    void setNombre(string);
    string getNombre();
    void setCorreo(string);
    string getCorreo();
    void setTelefono(int);
    int getTelefono();
    //otros metodos
    void comprarBoleto(Boleto b);
    void info_cliente();
};


/*Clase Cliente regular*/
class Cliente_regular : public Cliente {
private:
    int puntos_fidelidad;
public:
    //Metodo constructor
    Cliente_regular();
    Cliente_regular(int, string, string, int, int);
    //Get y Set
    void setPuntos_fidelidad(int);
    int getPuntos_fidelidad();
    //otros metodos
    void precio_boleto();
};


/*Clase Cliente VIP*/
class Cliente_vip : public Cliente {
private:
    string beneficios;
public:
    //Metodo constructor
    Cliente_vip();
    Cliente_vip(int, string, string, int, string);
    //Get y Set
    void setBeneficios(string);
    string getBeneficios();
    //otros metodos
    double calcular_descuento();
    void precio_boleto_descuento();
};
