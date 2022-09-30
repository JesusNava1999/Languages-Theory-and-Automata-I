/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Operaciones con lenguajes
Nombre del archivo: main.cpp
*/

#include <iostream>
#include <ctime>
#include <set>
#include <string>

using namespace std;

set<string> randomLanguage(int, int); // Construir un lenguaje de longitud máxima m 
string randomString(int, char*); // Contruir una cadena de longitud máxima n

set<string> joinLanguages(set<string>, set<string>); // Union de dos lenguajes 
set<string> interceptLanguages(set<string>, set<string>); // La intersección de dos lenguajes
set<string> subtractString(set<string>, set<string>); // La diferencia de dos lenguajes
set<string> concatenateString(set<string>, set<string>); // La concatenación de dos lenguajes
set<string> powString(set<string>, set<string>, int); // Potencia de un lenguaje *

void printLanguages(set<string>); // Mostrar un lenguaje
void printString(string); // Mostar una cadena
void cleanWord(char*, int);

int main() {

	srand((unsigned)time(NULL));

	int x, y, z;
	set<string> Language_1, Language_2, joinedLanguage, interceptedLanguage, subtractedString, concatenatedString, powerString;

	cout << "Cantidad maxima de cadenas: ";
	cin >> x;
	cout << endl << "Longitud maxima de cadena: ";
	cin >> y;
	cout << endl << "Potencia: ";
	cin >> z;

	//Print language A
	Language_1 = randomLanguage(x, y);
	cout << endl << "A: [ ";
	printLanguages(Language_1);
	cout << " ]" << endl;

	//Print language B
	Language_2 = randomLanguage(x, y);
	cout << "B: [ ";
	printLanguages(Language_2);
	cout << " ]" << endl << endl;

	//Print A union B
	joinedLanguage = joinLanguages(Language_1, Language_2);
	cout << "A union B: " << endl << "[ ";
	printLanguages(joinedLanguage);
	cout << " ]" << endl << endl;

	//Print A intersect B 
	interceptedLanguage = interceptLanguages(Language_1, Language_2);
	cout << "A intersect B: " << endl << "[ ";
	printLanguages(interceptedLanguage);
	cout << " ]" << endl << endl;

	//Print A - B
	subtractedString = subtractString(Language_1, Language_2);
	cout << "A less B: " << endl << "[ ";
	printLanguages(subtractedString);
	cout << " ]" << endl << endl;

	//Print cat (concatenación) A * B
	concatenatedString = concatenateString(Language_1, Language_2);
	cout << "A cat B: " << endl << "[ ";
	printLanguages(concatenatedString);
	cout << " ]" << endl << endl;

	//Print pow A^0, A^2, A^3, ... , A^p
	powerString = Language_1;
	for (int i = 0; i <= z; i++) {
		cout << "A pow " << i << ":" << endl << "[ ";
		printLanguages(powString(Language_1, powerString, i));
		cout << " ]" << endl << endl;
		if (i > 0) powerString = powString(Language_1, powerString, i);
	}

	return 0;
}

set<string> randomLanguage(int quantity, int length) { // Construir un lenguaje de longitud máxima m 
	set<string> Language;
	string word;
	char* auxWord = new char[length];

	for (int i = 0; i < quantity; i++) {
		int aux = rand() % (length - 0 + 1) + 0;
		Language.insert(randomString(aux, auxWord));
		cleanWord(auxWord, aux);
		word = auxWord;
	}
	delete[] auxWord;
	return Language;
}

string randomString(int length, char* auxWord) { // Contruir una cadena de longitud máxima n
	string word;
	for (int j = 0; j < length; j++) {
		auxWord[j] = rand() % (99 - 97 + 1) + 97;
		word = auxWord;
	}
	return word;
}

set<string> joinLanguages(set<string> Language_1, set<string> Language_2) { // Union de dos lenguajes 
	set<string> aux;
	for (const auto& a : Language_1) {
		aux.insert(a);
	}
	for (const auto& a : Language_2) {
		aux.insert(a);
	}
	return aux;
}

set<string> interceptLanguages(set<string> Language_1, set<string> Language_2) { // La intersección de dos lenguajes
	set<string> aux;
	for (const auto& a : Language_1) {
		for (const auto& b : Language_2) {
			if (a == b) {
				aux.insert(b);
			}
		}
	}
	return aux;
}

set<string> subtractString(set<string> Language_1, set<string> Language_2) { // La diferencia de dos lenguajes
	set<string> aux;
	for (const auto& a : Language_1) {
		aux.insert(a);
	}
	for (const auto& a : Language_1) {
		for (const auto& b : Language_2) {
			if (a == b) {
				aux.erase(a);
				aux.erase(b);
			}
		}
	}
	return aux;
}

set<string> concatenateString(set<string> Language_1, set<string> Language_2) { // La concatenación de dos lenguajes
	set<string> aux;
	for (const auto& a : Language_1) {
		for (const auto& b : Language_2) {
			aux.insert(a + b);
		}
	}
	return aux;
}

set<string> powString(set<string> Language, set<string> P_Language, int z) { // Potencia de un lenguaje *
	set<string> aux_1;
	aux_1.clear();
	if (z == 0) {
		aux_1.clear();
		aux_1.insert("");
		return aux_1;
	}
	else if (z == 1) {
		return Language;
	}
	else {
		for (const auto& a : P_Language) {
			aux_1.insert(a);
		}
		for (const auto& a : Language) {
			for (const auto& b : P_Language) {
				aux_1.insert(a + b);
			}
		}
		return aux_1;
	}
}

void printLanguages(set<string> Lenguage_x) { // Imprimir un lenguaje
	set<string> Language = Lenguage_x;
	// if (Language.empty() == true) Language.insert("");
	for (const auto& a : Language) {
		printString(a);
	}
}

void printString(string string_x) { // Imprimir una cadena
	string a = string_x;
	if (a == "" || string_x.empty() == true) cout << "<void>\t";
	else cout << a << "\t";
}

void cleanWord(char* auxWord, int length) {
	for (int j = 0; j <= (length + 1); j++)	auxWord[j] = '\0';
}