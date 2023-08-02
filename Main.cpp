#include<iostream>
#include "Tablero.h"
#include "TaTeTi.h"

int main(){
	char** tablero = crearTablero();
	inicializarTablero(tablero);

	mostrarTablero(tablero);
	jugarTateti(tablero);
	
	liberarMemoriaTablero(tablero);	
	return 0;
}


