# Proyecto-POO
Proyecto POO
El siguiente proyecto está hecho con el fin de manejar la reservación de boletos para una cadena de cines hipotética llamada CineCo. Creando de esta forma un sistema que permite al trabajador de la caja seleccionar lo que el cliente le indique como es la película, elegir su función según un los horarios, la sala y reservar su asiento según la disponibilidad. Tomando como consideración que los clientes se separan  entre los clientes regulares y VIP, donde los clientes regulares acumulan puntos de fidelidad con cada compra y los clientes VIP cuentan con un 20% de descuento del precio base. Cada cliente puede obtener uno o varios boletos mediante la composición, donde cada boleto pertenece a una función especifica la cual a su vez se compone de una película y una sala. Donde la clase sala administra la matriz de asientos disponibles y la clase película contienen los datos del filme. De forma que la cadena de relaciones va desde el cliente hasta el asiento físico dentro de la sala. Por último la clase caja permite al trabajador en caja del local ver los datos sobre las compras de boletos anteriores, la información de los clientes VIP y regulares y realizar el registro de nuevas compras.

# Funcionalidad
El programa permite el registro de los clientes, la selección de la película y la función despoblé, al igual que permite visualizar de forma interactiva el mapa de asientos en la sala y por último permite la generación de los boletos.
COnsta de un menu con las opciones iniciales y corre sobre consola.

# Casos donde dejaría de funcionar
- Si el usuario escribe un asiento inexistente
- En caso de que se pidan más de 10 asientos considerados que este está marcado como el límite
- Si el usuario ingresa 0 o un número negativo de asientos

# Consideraciones
El programa solo corre en la consola y está hecho con c++ standard por lo que corre en todos los sistemas operativos

    g++ *.cpp -o main.exe
    ./main.exe 

