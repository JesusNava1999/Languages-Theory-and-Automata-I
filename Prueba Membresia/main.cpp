/*
Estudiante: José De Jesús Nava Cuellar
Numero de Control: 18011108
Practica: Prueba de Membresia
Nombre del archivo: main.cpp
*/

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef struct {
  string header;
  string former;
  string latter;
} rule;

typedef vector<rule> grammar;

typedef set<string> Set;
typedef map<int, Set> row;
typedef map<int, row> table;

void init(Set, int);
void print(Set &A);
bool cyk(grammar, string);

int main() {
  grammar G;
  G.push_back({"B","C1","D1"});
  G.push_back({"D1","L","C2"});
  G.push_back({"C1","[","\0"});
  G.push_back({"C2","]","\0"});
  G.push_back({"B","L","D2"});
  G.push_back({"D2","C3","S"});
  G.push_back({"C3",";","\0"});
  G.push_back({"B","C4","D3"});
  G.push_back({"D3","C5","D4"});
  G.push_back({"D4","Q","D5"});
  G.push_back({"D5","C6","D6"});
  G.push_back({"D6","C7","D7"});
  G.push_back({"D7","B","C8"});
  G.push_back({"C4","i","\0"});   
  G.push_back({"C5","(","\0"});   
  G.push_back({"C6",")","\0"}); 
  G.push_back({"C7","t","\0"});
  G.push_back({"C8","f","\0"});
  G.push_back({"B","C4","D8"});
  G.push_back({"D8","C5","D9"});
  G.push_back({"D9","Q","D10"});
  G.push_back({"D10","C6","D11"});
  G.push_back({"D11","C7","D12"});
  G.push_back({"D12","B","D13"});
  G.push_back({"D13","C9","D14"});
  G.push_back({"D14","B","C8"});
  G.push_back({"C9","e","\0"});
  G.push_back({"B","C10","D15"});
  G.push_back({"D15","C11","Q"});
  G.push_back({"C10","x","\0"});
  G.push_back({"C11",":","\0"});
  G.push_back({"B","P","D16"});
  G.push_back({"D16","C12","D17"});
  G.push_back({"D17","Q","D18"});
  G.push_back({"C12","?","\0"});
  G.push_back({"B","0","\0"});
  G.push_back({"B","1","\0"});
  G.push_back({"L","L","D2"});
  G.push_back({"L","C4","D3"});
  G.push_back({"L","C4","D8"});
  G.push_back({"L","C10","D15"});
  G.push_back({"L","C1","D1"});
  G.push_back({"L","0","\0"});
  G.push_back({"L","1","\0"});
  G.push_back({"S","C4","D3"});
  G.push_back({"S","C4","D8"});
  G.push_back({"S","C10","D15"});
  G.push_back({"S","P","D16"});
  G.push_back({"S","C1","D1"});  
  G.push_back({"S","0","\0"});
  G.push_back({"S","1","\0"});  
  G.push_back({"S","L","D2"});
  G.push_back({"Q","P","D16"});
  G.push_back({"Q","0","\0"});
  G.push_back({"Q","1","\0"});  
  G.push_back({"P","0","\0"});
  G.push_back({"P","1","\0"});
  /* cout << endl << "Gramatica en FNC" << endl;  
   for (vector<rule>::iterator it = G.begin() ; it != G.end(); ++it){
    if(it->latter == "\0"){
      cout << ' ' << it->header << " -> " << it->former << " "<< it->latter << "\t\t\tTerminal" << endl;
    } else {
      cout << ' ' << it->header << " -> " << it->former << " "<< it->latter << endl;
    }    
  }   */
  string w = "";
  cout << "Ingrese una cadena: ";
  cin >> w;
  if(cyk(G,w)){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

bool cyk(grammar G, string w){ 
  bool flag = false;
  Set *A = new Set[w.length()];
  row *r = new row[w.length()];
  table t; 
  for (int i=1; i<=w.length(); i++){
    for (vector<rule>::iterator it = G.begin() ; it != G.end(); ++it){
      if(w[i-1] == it->former[0]){   
        t[1][i].insert(it->header);    
      }       
    }
  }
  for (int j=2; j<=w.length(); j++){
    for(int i=1; i<=w.length()-j+1; i++){
      for(int k=1; k<=j-1; k++){
        for(auto x: t[k][i]){
          for (auto y: t[j-k][i+k]){
            for (vector<rule>::iterator it = G.begin() ; it != G.end(); ++it){
              if((x==it->former)&&(y==it->latter)){
                t[j][i].insert(it->header);
              } else {
                t[j][i].insert(" ");
              }
            }   
          }
        }
      }
    }
  }
  cout << endl;  
  for(int i=0; i<w.length(); i++) {
    cout << "[ ";
    for (int j=0; j<w.length()-i; j++){
      print(t[j+1][i+1]);
    }
    cout << " ]"<< endl;
  }
  cout << endl;
  for(int i=0; i<=w.length(); i++){
    for (auto x: t[i][1] ){
      if(x=="S"){
        flag = true;
      }
    }   
  } 
  delete []A; 
  delete []r;
  return flag;
}

void print(Set &A) {
  for (auto x: A) {
    cout << x << " ";
  }
  cout << "\t\t";
}