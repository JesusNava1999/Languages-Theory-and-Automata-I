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
	
	// mcomp.printMaquinaTuring(); // Imprimir Mcomp
	cout << endl;
	// minc.printMaquinaTuring(); // Imprimir Minc
	
	cout << "Ingrese w: ";
	cin >> w;
	
	Cinta cinta (w); // Inicializar cinta
	cout << endl << "\t\t\tw: ";
	cinta.print(); // Imprimir cinta
	cout << endl << endl;
	
	cinta = mcomp.complementoAUnos(cinta); // Proceso de Maquina Complemento a Unos
	
	cout << endl << "\t\t\tC(w): ";
	cinta.print();	// Imprimir cinta
	cout << endl << "\t\t\t+\t\t1" << endl;
	cout << "\t\t\t----------------"<< endl << endl;
		
	minc.complementoADoses(cinta,acarreo); // Proceso de Maquina Complemento a Doses
	cout << "\t\t\t";
	cinta.print();
	
	if(acarreo){
		cout << " c= " << "1" << endl;
	} else {
		cout << " c= " << "0" << endl;
	}
	cout << endl;
	
	return 0;
}
