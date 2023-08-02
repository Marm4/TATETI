#ifndef TATETI_H
#define TATETI_H

#include<fstream>

//Recibe una posicion del tablero, un caracter que se refiere a
//el elemento que acaba de jugar
//En el caso de que el espacio en el tablero este "vacio"
//guarda el caracter y retorna EXITO (0). En caso de no estar disponible
//retorna ERROR(-1).
int guardarEnTablero(char* posicionTablero, char turnoDe);

//Recibe por parametro de tipo string si se pide una fila o una columna
//Devuelve el numero ingresado.
//No se tiene en cuenta si el usuario ingresa un numero fuera del rango.
int pedirDato(std::string tipo);

//Recibe una posicion del tablero, un caracter que se refiere a
//el elemento que acaba de jugar
//En caso de ser compatibles, el caracter sera borrado
//retorna EXITO en caso de ser borrar, ERROR de lo contrario
int borrarCaracter(char* posicionTablero, char turnoDe);

//Recibe un tablerio de tamanio fijo, un caracter que se refiere a
//el elemento que le toca jugar
//Llama a la funcion guardarEnTablero. En caso de que el retorno
//de esta funcion sea ERROR, se vuelve a llamar a si misma recursivamente
//caso contrario, retorna.
void jugarRonda(char** tablero, char turnoDe, int cantidadRondas);

//Recibe un archivo y un tablero
//Escribe sobre el archivo el estado del tablero
void actualizarArchivo(std::ofstream &archivo, char** tablero);

//Recibe un tablero de tamanio fijo.
//Llama iterativamente a la funcion jugar ronda.
//Una vez pasadas las 3 rondas, llama a la funcion
//estadoTablero, la cual en caso de retornar true
//termina la iteracion.
void jugarTateti(char** tablero);


#endif
