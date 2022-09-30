/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Generación aleatoria de cadenas
Nombre del archivo: main.cpp
*/
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
void cleanWord(char *auxWord, int length);
int main(){
	srand((unsigned)time(NULL));	    
	int x=0, y=0;
  char auxWord[100];
  string word = ""; 
	cout << "Cantidad de cadenas: ";
	cin >> x;
	cout << endl <<"Longitud maxima de cadena: ";	
	cin >> y;	  
	for (int i=0; i<=x; i++){  
    int aux = rand() % (y-0+1) + 0;
		for (int j=0; j<aux; j++){
			auxWord[j] = rand() % (122-97+1) + 97;	
      word = auxWord;      									
		}	
    if(aux==0){
      cout << "<void>" << endl;
    }
    else {
      cout << word << endl;
    }    
    cleanWord(auxWord,aux);	
    word = auxWord;	
	}				
	return 0;
}

void cleanWord(char *auxWord, int length){
  for (int j=0; j<=length; j++){
		auxWord[j] = '\0';	      									
	}	
}
