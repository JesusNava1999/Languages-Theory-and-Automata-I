/* 
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Composicionalidad
Nombre del archivo: MInc.cpp
*/

#include <stddef.h>
#include <string>
#include <map>
#include <iostream>

#include "Cinta.h"
#include "MInc.h"

using namespace std;

MInc::MInc(){
	// Valores de los estados
	q0 = 0;
	q1 = 1;
	q2 = 2;
	q3 = 3;
	q4 = 4;
	q5 = 5;
	q6 = 6;
	
	// Definir estado inicial
	init = q0;
	
	// Definir los estados finales
	finalStates.insert(q5);
	finalStates.insert(q6);
	
	// Transiciones del estado q0
	delta[q0]['\0'] = q1;
	
	// Transiciones del estado q1
	delta[q1]['0'] = q2;
	delta[q1]['1'] = q1; 
	delta[q1]['\0'] = q3; 
	
	// Transiciones del estado q2
	delta[q2]['0'] = q2;
	delta[q2]['1'] = q2; 
	delta[q2]['\0'] = q4; 
	
	// Transiciones del estado q3
	delta[q3]['\0'] = q5;
	
	// Transiciones del estado q4
	delta[q4]['\0'] = q6;
}

void MInc::complementoADoses(Cinta &cinta, bool &acarreo){	
	unsigned aux = init;
	int limit = cinta.Size()-1;
	cinta.end();
	int place = cinta.Index();
	while(cinta.Index()>=0){
		if(cinta.Index()==0){
			if(acarreo){
				cinta.write(0,'1');
			} else {
				cinta.write(0,'0');
			}	
		}
		for(int i=0; i<=limit; i++){
			if(place==i){
				cout << ".";
				if((i==1)&&(place==1)){
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
		if(cinta.read(place)==(char)32){
		} else {
			if(acarreo){
				if(cinta.read(place)=='0'){
					cinta.write(place,'1');
					acarreo = false;
				} else if(cinta.read(place)=='1'){
					cinta.write(place,'0');
					acarreo = true;				
				}				
			}
		}
		cout << endl;
		aux = transition(aux, cinta.read(place), delta);
		cinta.left();
		place=cinta.Index();	
		
	}	
	if(acarreo){
		cinta.write(0,'1');
	} else {
		cinta.write(0,'0');
	}
}

void MInc::printMaquinaTuring(){
	cout << "Init: " << init << endl << endl;
	
	for (map<unsigned,event>::iterator it=delta.begin(); it!=delta.end(); ++it){		
		for (map<char,unsigned>::iterator it_1 = it->second.begin(); it_1!=it->second.end(); ++it_1){
			cout << "[" << it->first;
			cout << ","<< it_1->first << "]: " << it_1->second << endl;
		}
	}
	
	cout << endl << "Final [ "; 
	for(const auto& a: finalStates){
		cout << a << " ";
	}
	cout << "]" << endl;
}

unsigned MInc::transition(unsigned currentState, char event, map<unsigned, map<char, unsigned>> delta){	
	map<unsigned, map<char, unsigned>>::iterator it = delta.begin();
	unsigned aux = 0;
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
