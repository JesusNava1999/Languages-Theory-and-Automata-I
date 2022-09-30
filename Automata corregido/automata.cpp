#include <iostream>
#include <stddef.h>
#include "automata.h"

automata::automata(){	
	q0 = 0;
  q1 = 1;
  q2 = 2;
  q3 = 3;
  init = q0;
  finalState = q0;

  delta[q0]['0']=q2;  
  delta[q0]['1']=q1;
  delta[q1]['0']=q3;
  delta[q1]['1']=q0;
  delta[q2]['0']=q0;
  delta[q2]['1']=q3;
  delta[q3]['0']=q1;
  delta[q3]['1']=q2;


}

void automata::print(){
for (map<unsigned,event>::iterator it=delta.begin(); it!=delta.end(); ++it){		
		for (map<char,unsigned>::iterator it_1 = it->second.begin(); it_1!=it->second.end(); ++it_1){
      cout << "[" << it->first;
			cout << ","<< it_1->first << "]: " << it_1->second << endl;
		}
	}
	
	cout << endl << "Final [ "<< finalState << " ]" << endl;
}

unsigned automata::transition(unsigned currentState, char event, map<unsigned, map<char, unsigned>> delta){	
	map<unsigned, map<char, unsigned>>::iterator it = delta.begin();
	unsigned aux = 0;
	for (it=delta.begin(); it!=delta.end(); ++it){
		if(currentState == it->first){
			for (map<char,unsigned>::iterator it_1 = it->second.begin(); it_1!=it->second.end(); ++it_1){
				if(event == it_1->first){
					aux = it_1->second;					
				}
			}
		}	
	}
	return aux;
}

map<unsigned, map<char, unsigned>> automata::Delta(){
	return delta;
}

bool automata::test(string word){
	bool flag = false;
	unsigned aux = init;
	if(word.length()>0){
		for(unsigned i=0; i < word.length(); i++){
			aux = transition(aux, word[i], delta);
		}		
		if(aux==finalState){
			flag = true;
		}		
		if(flag){
			return true;
		} {
			return false;
		}
	} else {	
		return true;
	}
}
