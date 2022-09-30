/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Composicionalidad
Nombre del archivo: MComp.h
*/

#ifndef MComp_h
#define MComp_h

#include <stddef.h>
#include <string>
#include <map>
#include <iostream>

#include "Cinta.h"

using namespace std;

class MComp {
	unsigned q0, q1, q2;
	unsigned finalState;
	unsigned init;
	
	typedef map<char, unsigned> event;
	typedef map<unsigned, event> state;	
	
	state delta;	
	
public:
	MComp();
	
	Cinta complementoAUnos(Cinta &);	
	
	void printMaquinaTuring();		
	
	unsigned transition(unsigned, char, map<unsigned, map<char, unsigned>>);	
	
};

#endif
