/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Composicionalidad
Nombre del archivo: Cinta.h
*/

#ifndef Cinta_h
#define Cinta_h

#include <stddef.h>
#include <string>
#include <map>

using namespace std;

class Cinta {
	
	typedef map<int,char> tape;
	tape cinta;
	int index;
	
public:
	
	Cinta(string);
	
	char read(int);
	void write(int,char);
	void left();
	void right();
	int Size();
	int Index();
	void init();
	void end();
	void print();
	
};

#endif
