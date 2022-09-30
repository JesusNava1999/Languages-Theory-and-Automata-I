/* 
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Composicionalidad
Nombre del archivo: Cinta.cpp
*/

#include <iostream>
#include <stddef.h>
#include <string>
#include "Cinta.h"

using namespace std;

Cinta::Cinta(string w){
	index = 2;
	while(index <= w.length()+1){
		cinta[index] = w[index-2];
		right();
	}
	init();
}



void Cinta::right(){
	index++;
}

void Cinta::left(){
	index--;
}

char Cinta::read(int x){
	return cinta[x];
}

void Cinta::write(int x, char c){
	cinta[x] = c;
}

int Cinta::Size(){
	return (cinta.size());
}

int Cinta::Index(){
	return index;
}

void Cinta::init(){
	while(Index()!=2){
		left();
	}
}

void Cinta::end(){
	while(Index()!=Size()-1){
		right();
	}
}

void Cinta::print(){
	int limit = Size()+1;
	for(int i=Index()-1; i<=limit; i++){
		cout << read(i);
	}
}
