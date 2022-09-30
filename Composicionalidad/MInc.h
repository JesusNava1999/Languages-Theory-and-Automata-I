/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Composicionalidad
Nombre del archivo: MInc.h
*/

#ifndef MInc_h
#define MInc_h

#include <stddef.h>
#include <string>
#include <map>
#include <set>
#include <iostream>

#include "Cinta.h"

using namespace std;

class MInc {		
	unsigned q0, q1, q2, q3, q4, q5, q6;
	set<unsigned> finalStates;
	unsigned init;
	
	typedef map<char, unsigned> event;
	typedef map<unsigned, event> state;	
	
	state delta;		
	
public:
	
	MInc();	
	
	void complementoADoses(Cinta &, bool &);
	
	void printMaquinaTuring();		
	
	unsigned transition(unsigned, char, map<unsigned, map<char, unsigned>>);	
	
};

#endif
