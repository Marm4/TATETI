#include <string>
#include<iostream>

#include "TaTeTi.h"
#include "Tablero.h"

#define EXITO 0
#define ERROR -1

using namespace std;

int guardarEnTablero(char* posicionTablero, char turnoDe){
	int retorno = EXITO;
	
	if(*posicionTablero == '_' || *posicionTablero == ' '){
		*posicionTablero = turnoDe;
	}
	
	else{
		cout<<"El lugar elegido ya esta ocupado"<<endl;
		retorno = ERROR;
	}
	
	return retorno;
}

int pedirDato(string tipo){
	int dato;
	cout<<"Ingrese "<<tipo<<endl;
	cin>>dato;
	return dato;
}

int borrarCaracter(char* posicionTablero, char turnoDe){
	int retorno = ERROR;
	if(*posicionTablero == turnoDe){
		*posicionTablero = ' ';	
		retorno = EXITO;
	}
	if(retorno == ERROR){
		cout<<"ERROR, Ingrese una posicion en la cual se encuentre su caracter"<<endl;
	}	
	return retorno;
}

void jugarRonda(char** tablero, char turnoDe, int cantidadRondas){
	int columna, fila;
	
	cout<<endl;
	cout<<"Turno de "<<turnoDe<<endl;
	
	if(cantidadRondas>=3){
		do{
		cout<<"Elija el caracter que desea mover"<<endl;
		columna = pedirDato("Columna")-1;
		fila = pedirDato("Fila")-1;
		}
		while(borrarCaracter(&tablero[fila][columna], turnoDe));
		
		cout<<"Elija donde quiere colocarlo"<<endl;
	}
	
	columna = pedirDato("Columna")-1;
	fila = pedirDato("Fila")-1;
	
	if(guardarEnTablero(&tablero[fila][columna], turnoDe) == ERROR){
		jugarRonda(tablero, turnoDe, cantidadRondas-1);
	}
	else {
		cout<<endl;
		mostrarTablero(tablero);
	}
}

void actualizarArchivo(ofstream &archivo, char** tablero){
	for(int i=0; i<FILA; i++){
		for(int j=0; j<COLUMNA; j++){
			archivo<<tablero[i][j];
			if(j!=2){
				archivo<<"|";
			}
		}
		archivo<<endl;
	}	
	archivo<<endl;
}

void jugarTateti(char** tablero){
	ofstream archivo;
	archivo.open("TaTeTi.txt", ios::out); 
	bool ganador = false;
	int cantidadRondas=0;

	while(!ganador){
		jugarRonda(tablero, 'X', cantidadRondas);
	
		if(cantidadRondas>=2){
			ganador = estadoTablero(tablero);		
		}
		
		if(!ganador) {
			jugarRonda(tablero, 'O', cantidadRondas);
			cantidadRondas++;
		
			if(cantidadRondas>2){
				ganador = estadoTablero(tablero);
			}
		}	
		actualizarArchivo(archivo, tablero);
	}
	archivo.close();	
}
