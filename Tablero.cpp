#include<iostream>
#include "Tablero.h"

using namespace std;

char** crearTablero(){
	char** tablero = new char*[FILA];
	for(int i=0; i<FILA; i++){
		tablero[i] = new char[COLUMNA];
	}
	return tablero;
}

void inicializarTablero(char** tablero){
	for(int i=0; i<FILA; i++){
		for(int j=0; j<COLUMNA; j++){
			if(i!=2){
				tablero[i][j] = '_';
			}
			else{
				tablero[i][j] = ' ';
			}
		}	
	}
}

void mostrarTablero(char** tablero){
	
	for(int i=0; i<FILA; i++){
		cout<<"\t";
		for(int j=0; j<COLUMNA; j++){
			cout<<tablero[i][j];
			if(j!=2){
				cout<<"|";
			}	
		}
		cout<<endl;
	}	
}

bool estadoTablero(char** tablero){
	bool ganador = false;
	int i=0;

	while(!ganador && i<3){
		if((tablero[i][0] == tablero[i][1]) && (tablero[i][1] == tablero[i][2])){
			if(tablero[i][0] != ' ' && tablero[i][0] != '_'){
				ganador = true;
				mostrarGanador(tablero[i][0]);
			}

		}
		else if((tablero[0][i] == tablero[1][i]) && (tablero[1][i] == tablero[2][i])){
			if(tablero[0][i] != ' ' && tablero[0][i] != '_'){
				ganador = true;
				mostrarGanador(tablero[0][i]);
			}
		}
		i++;
	}
	if(!ganador){
		if((tablero[0][0] == tablero[1][1]) && (tablero[1][1] == tablero[2][2])){
			if(tablero[0][0] != ' ' && tablero[0][0] != '_'){
				ganador = true;
				mostrarGanador(tablero[0][0]);
			}
		}
		else if((tablero[0][2] == tablero[1][1]) && (tablero[1][1] == tablero[2][0])){
			if(tablero[0][2] != ' ' && tablero[0][2] != '_'){
				ganador = true;
				mostrarGanador(tablero[0][2]);
			}
		}
	}
	return ganador;
}

void mostrarGanador(char ganador){
	cout<<"Feclidades, el ganador es: "<<ganador<<endl;
}

void liberarMemoriaTablero(char** tablero){
	for(int i=0; i<COLUMNA; i++){
		delete[] tablero[i];
	}
	delete [] tablero;
}

