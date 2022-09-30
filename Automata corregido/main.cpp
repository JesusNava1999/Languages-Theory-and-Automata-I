#include <iostream>
#include <ctime>
#include <map>
#include <string>
#include <set>
#include "automata.h"

multiset<string> randomLanguage(int, int); 
string randomString(int, char*); 

void printLanguages(multiset<string>);
void printString(string); 
void cleanWord(char*, int);

using namespace std;

int main ()
{	
	srand((unsigned)time(NULL));
	
	int n,m;
	multiset<string> Language;
	automata A;
	
	//cout << "Automata: " << endl;
	//A.print();	
	
	cout << "Numero de cadenas (n): ";
	cin >> n;
	cout << "Longitud (m): ";
	cin >> m;
	cout << endl;
	
	Language = randomLanguage(n,m);
	//printLanguages(Language);		
	
	for (const auto& a : Language) {
		printString(a);			
		if(a.length() >= 8){
			cout << "\t";
		} else {
			cout << "\t\t";
		}		
		if((A.test(a))==true){
			cout << ": accepted";
		} else {
			cout << ": rejected";
		}
	}
  cout << endl;	
	return 0;
}

multiset<string> randomLanguage(int quantity, int length) { 
	multiset<string> Language;
	string word;
	char* auxWord = new char[length];
	
	for (int i = 0; i < quantity; i++) {
		int aux = rand() % (length - 0 + 1) + 0;
		Language.insert(randomString(aux,auxWord));
		cleanWord(auxWord, aux);
		word = auxWord;
	}
	delete[] auxWord;
	return Language;
}

string randomString(int length, char* auxWord) { 
	string word;
	for (int j = 0; j < length; j++) {
		auxWord[j] = rand() % (49 - 48 + 1) + 48;
		word = auxWord;
	}
	return word;
}

void printLanguages(multiset<string> Lenguage_x) { 
	multiset<string> Language = Lenguage_x;
	for (const auto& a : Language) {
		printString(a);
	}
}

void printString(string string_x) {
	string a = string_x;
	if (a == "") cout << endl <<"<void>";
	else cout << endl << a;
}

void cleanWord(char* auxWord, int length) {
	for (int j = 0; j <= (length + 10); j++)	auxWord[j] = '\0';
}

