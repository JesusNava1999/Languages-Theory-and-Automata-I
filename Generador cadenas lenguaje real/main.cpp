#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void cleanWord(char *auxWord, int length);

int main(){   
	int x = 10, y = 3;
  /* Banderas para generacion de decimales, exponentes y signos */ 
  char bandera_0, bandera_1, bandera_2, bandera_3, bandera_4, bandera_5;    
  string matisaEntera = ""; 
  string matisaDecimal = "";
  string matisa = "";
  string exponente = "";
  string cadena = "";

  char* auxWord_0 = new char[y];
  int i=0;    
  srand((unsigned)time(nullptr));	
	while(i!=x){        
    int aux_0 = rand() % (y - 1 + 1) + 1;
		for (int j=0; j<aux_0; j++){      
			auxWord_0[j] = rand() % ('9'-'0' + 1) + '0';         									
		}	
    matisaEntera = auxWord_0;

    bandera_0 = rand() % ('1' - '0' + 1) + '0';
    if (bandera_0 == '0'){
      char* auxWord_1 = new char[y];
      auxWord_1[0]='.';
      int aux_1 = rand() % (y - 1 + 1) + 1;
		  for (int j=1; j<aux_1+1; j++){
        auxWord_1[j] = rand() % ('9'-'0' + 1) + '0';             									
		  }	
      matisaDecimal = auxWord_1;
      matisa = matisaEntera + matisaDecimal;
      delete [] auxWord_1;

      bandera_1 = rand() % ('1' - '0' + 1) + '0';
      if (bandera_1 == '0'){
        char* auxWord_2 = new char[y];
        bandera_2 = rand() % ('1' - '0' + 1) + '0';
        if (bandera_2 == '0'){
          auxWord_2[0]='e';
        } else {
         auxWord_2[0]='E';
        }
        exponente = auxWord_2;
        delete [] auxWord_2;

        bandera_3 = rand() % ('1' - '0' + 1) + '0';
        if (bandera_3 == '0'){
          char* auxWord_3 = new char[y];
          bandera_4 = rand() % ('1' - '0' + 1) + '0';
          if (bandera_4 == '0'){
            auxWord_3[0] = '+';
          } else {
            auxWord_3[0] = '-';
          }
          exponente = exponente + auxWord_3;
          delete [] auxWord_3;
        }
      }      
    }
    bandera_5 = rand() % ('1' - '0' + 1) + '0';
    if (bandera_3 == '0'){
      char* auxWord_4 = new char[y];
      int aux_2 = rand() % (y - 1 + 1) + 1;
		  for (int j=0; j<aux_2; j++){      
			  auxWord_4[j] = rand() % ('9'-'0' + 1) + '0';         									
		  }	
      exponente = exponente + auxWord_4;
      delete [] auxWord_4;
    }
    cadena = matisa + exponente;
    if(cadena.length()!=0){
      cout << cadena << endl;
      i++;
    }     
    matisaEntera = ""; 
    matisaDecimal = "";
    matisa = "";
    exponente = "";
    cadena = "";    
    cleanWord(auxWord_0, aux_0);
  }
  delete [] auxWord_0;
	return 0;
}

void cleanWord(char *auxWord, int length){
  for (int j=0; j<=(length+1); j++){
		auxWord[j] = '\0';	      									
	}	
}