/* 
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Composicionalidad
Nombre del archivo: MComp.cpp
*/

#include <iostream>
#include <stddef.h>
#include "MComp.h"


MComp:: MComp(){	
	// Valores de los estados
	q0 = 0;
	q1 = 1;
	q2 = 2;
	// Definir estado inicial
	init = q0;
	// Definir los estados finales
	finalState = q2;
	// Transiciones del estado q0
	delta[q0]['\0'] = q1;
	
	// Transiciones del estado q1
	delta[q1]['0'] = q1;
	delta[q1]['1'] = q1; 
	delta[q1]['\0'] = q2; 
	
}

void MComp::printMaquinaTuring(){
	cout << "Init: " << init << endl << endl;
	for (map<unsigned,event>::iterator it=delta.begin(); it!=delta.end(); ++it){		
		for (map<char,unsigned>::iterator it_1 = it->second.begin(); it_1!=it->second.end(); ++it_1){
			cout << "[" << it->first;
			cout << ","<< it_1->first << "]: " << it_1->second << endl;
		}
	}
	
	cout << endl << "Final [ " << finalState << " ]" << endl;
}

unsigned MComp::transition(unsigned currentState, char event, map<unsigned, map<char, unsigned>> delta){  
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

Cinta MComp::complementoAUnos(Cinta &cinta){
	unsigned aux = init;
	int limit = cinta.Size()+1;
	int place = cinta.Index();
	while(place <= limit){		
		for(int i=2; i<=limit; i++){
			if(place==i){
				cout << ".";
				if((i==1)&&(place+1==1)){
					cout << (char)32;
				} else if((i==(limit))&&(place==(limit))){
					cout << (char)32;
				} else {
					cout << cinta.read(i);
				}	
			} else {				
				cout << cinta.read(i);							
			}		
		}		
		aux = transition(aux, cinta.read(place), delta);
		if(cinta.read(place)=='0'){
			cinta.write(place,'1');
			cout << "\t1 -> R" << endl;
		} else if(cinta.read(place)=='1') {
			cinta.write(place,'0');			
			cout << "\t0 -> R" << endl;
		}
		cinta.right();
		place = (cinta.Index());
	}
	cinta.init();	
	return cinta;
}

