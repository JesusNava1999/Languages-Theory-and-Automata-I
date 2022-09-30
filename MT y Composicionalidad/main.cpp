/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Composicionalidad
Nombre del archivo: main.cpp
*/

#include <iostream>
#include <map>
#include <string>
#include "cinta.h"
#include "MComp.h"
#include "MInc.h"


using namespace std;

int main() {	
	MComp mcomp;
	MInc minc;
	string w;	
	bool acarreo = true;
	cout << endl;
	
	cout << "Ingrese w: ";
	cin >> w;
	
	Cinta cinta (w); // Inicializar cinta
	cout << endl << endl << "\tw: ";
	cinta.print(); // Imprimir cinta
	cout << endl << endl;
	
	cinta = mcomp.complementoAUnos(cinta); // Proceso de Maquina Complemento a Unos
	
	cout << endl << endl << "\tC(w): ";
	cinta.print();	// Imprimir cinta
	cout << endl << endl;
		
	cinta = minc.complementoADoses(cinta,acarreo); // Proceso de Maquina Complemento a Doses
	cout << endl << "\tw': ";
	cinta.print();
		
	return 0;
}
