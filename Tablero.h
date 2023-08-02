#ifndef TABLERO_H
#define TABLERO_H

#define COLUMNA 3
#define FILA 3


//Reserva memoria para un tablero
//Retorna la direccion de memoria al tablero
char** crearTablero();

//Recibe un puntero a un tablero de tamanio FILAxCOLUMNA
//Incicializa el tablero con valores "_" y " ".
void inicializarTablero(char** tablero);

//Muestra el estado del tablero por pantalla
void mostrarTablero(char** tablero);

//Recibe un puntero a un tablero de tamanio FILAxCOLUMNA
//Evalua si hay algun ganador, de haberlo llama a mostrarGanador
//Retorna true en caso de haber ganador, false en el caso contrario
bool estadoTablero(char** tablero);

//Recibe un caracter por parametro
//Imprime por pantalla al ganador
void mostrarGanador(char ganador);

//Recibe un puntero a un tablero de tamanio FILAxCOLUMNA
//Libera la memoria del tablero
void liberarMemoriaTablero(char** tablero);


#endif
