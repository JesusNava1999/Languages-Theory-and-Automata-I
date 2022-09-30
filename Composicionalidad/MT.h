/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Composicionalidad
Nombre del archivo: MT.h
*/

#ifndef MT_h
#define MT_h

#include <stddef.h>
#include <string>
#include <set>
#include <map>

using namespace std;

class MT {
	unsigned q0, q1, q2, q3;
	unsigned finalState;
	unsigned init;
	
	typedef map<int,char> tape;
	typedef map<char, unsigned> event;
	typedef map<unsigned, event> state;	
	
	state delta;
	tape cinta;
	
	
public:
	MT();
	
	void complementoAUnos();
	
	void inicializarCinta(string);
	
	void printCinta();
	
	void printMaquinaTuring();
	
	char complementoADoses();
	
	unsigned transition(unsigned, char, map<unsigned, map<char, unsigned>>);	
	
};

#endif
