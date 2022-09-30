/* 
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Composicionalidad
Nombre del archivo: MT.cpp
*/

#include <iostream>
#include <stddef.h>
#include "MT.h"

MT::MT(){	
	// Valores de los estados
	q0 = 0;
	q1 = 1;
	q2 = 2;
	// Definir estado inicial
	init = q0;
	// Definir los estados finales
	finalState = q2;
	// Transiciones del estado q0
	delta[q0]['0'] = q0;
	delta[q0]['1'] = q0;
	delta[q0][(char)32] = q1;
	
	// Transiciones del estado q1
	delta[q1]['0'] = q1;
	delta[q1]['1'] = q1; 
	delta[q1][(char)32] = q2; 
	
	// Transiciones del estado q2 
	
}

void MT::printMaquinaTuring(){
	for (map<unsigned,event>::iterator it=delta.begin(); it!=delta.end(); ++it){		
		for (map<char,unsigned>::iterator it_1 = it->second.begin(); it_1!=it->second.end(); ++it_1){
			cout << "[" << it->first;
			cout << ","<< it_1->first << "]: " << it_1->second << endl;
		}
	}
	
	cout << endl << "Final [ " << finalState << " ]" << endl;
}

unsigned MT::transition(unsigned currentState, char event, map<unsigned, map<char, unsigned>> delta){  
	map<unsigned, map<char, unsigned>>::iterator it = delta.begin();
	unsigned aux;
	for (it=delta.begin(); it!=delta.end(); ++it){
		if(currentState == it->first){
			for (map<char,unsigned>::iterator it_1 = it->second.begin(); it_1!=it->second.end(); ++it_1){
				if(event == it_1->first){
					aux = it_1->second;					
				}
			}
		}	
	}
	return aux;
}

void MT::inicializarCinta(string w){
	for(int i = 2; i<=w.length()+1; i++){
			cinta[i] = w[i-2];
	}
	cout << endl;
}

void MT::printCinta(){
	int limit = cinta.size();
	for (int iterator = 0; iterator <= limit+1; iterator++){
		cout << cinta[iterator];
	}
}

void MT::complementoAUnos(){
	unsigned aux = init;
	int limit = cinta.size();
	for (int i = 1;  i <= limit;  i++){
		for(int j = 1; j <= limit; j++){
			if(i==j){
				cout << ".";
				if((j==1)&&(i==1)){
					cout << (char)32;
				} else if((j==(limit))&&(i==(limit))){
					cout << (char)32;
				} else {
					cout << cinta[j];
				}	
			} else {				
				cout << cinta[j];							
			}						
		}				
		cout << endl;
		aux = transition(aux, cinta[i], delta);		
		if(cinta[i]=='0'){
			cinta[i]='1';
		} else if(cinta[i]=='1') {
			cinta[i]='0';
		}
	}		
}

char MT::complementoADoses(){
	bool acarreo = true;
	int i=cinta.size();
	while(i!=0){
		if(cinta[i]==(char)32){
			i--;
		} else {
			if(acarreo){
				if(cinta[i]=='0'){
					cinta[i]='1';
					acarreo=false;
				} else if(cinta[i]=='1') {
					cinta[i]='0';
					acarreo=true;
				}
			}
			i--;
		}	
	}	
	if(acarreo){
		cinta[0]='1';
	} else {
		cinta[0]='0';
	}
	return acarreo;
}
