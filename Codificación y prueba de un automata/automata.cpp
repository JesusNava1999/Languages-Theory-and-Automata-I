#include <iostream>
#include <stddef.h>
#include "automata.h"

automata::automata(){	
	q0 = 0;
	q1 = 1;
	q2 = 2;
	q3 = 3;
	init = q0;
	
	finalStates.insert(automata::q0);
	
	e_1.insert(pair<char, unsigned>('0',q0));
	e_2.insert(pair<char, unsigned>('1',q0));
	e_3.insert(pair<char, unsigned>('0',q1));
	e_4.insert(pair<char, unsigned>('1',q1));
	e_5.insert(pair<char, unsigned>('0',q2));
	e_6.insert(pair<char, unsigned>('1',q2));
	e_7.insert(pair<char, unsigned>('0',q3));
	e_8.insert(pair<char, unsigned>('1',q3));	
	
	delta.insert(pair<unsigned, event>(q0, e_5));
	delta.insert(pair<unsigned, event>(q0, e_4));	
	
	delta.insert(pair<unsigned, event>(q1, e_7));
	delta.insert(pair<unsigned, event>(q1, e_2));	
	
	delta.insert(pair<unsigned, event>(q2, e_1));
	delta.insert(pair<unsigned, event>(q2, e_8));
	
	delta.insert(pair<unsigned, event>(q3, e_3));
	delta.insert(pair<unsigned, event>(q3, e_6));
	
}

void automata::print(){
	cout << "Init: " << init << endl << endl;
	
	for (map<unsigned,event>::iterator it=delta.begin(); it!=delta.end(); ++it){
		cout << "[" << it->first;
		
		for (map<char,unsigned>::iterator it_1 = it->second.begin(); it_1!=it->second.end(); ++it_1){
			cout << ","<< it_1->first << "]: " << it_1->second << endl;
		}
	}
	
	cout << endl << "Final [ "; 
	for(const auto& a: finalStates){
		cout << a << " ";
	}
	cout << "]" << endl;
}

unsigned automata::transition(unsigned currentState, char event, multimap<unsigned, map<char, unsigned>> delta){	
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

multimap<unsigned, map<char, unsigned>> automata::Delta(){
	return delta;
}

bool automata::test(string word){
	bool flag = false;
	unsigned aux = init;
	if(word.length()>0){
		for(unsigned i=0; i < word.length(); i++){
			aux = transition(aux, word[i], delta);
		}
		for (const auto& a : finalStates) {
			if(aux==a){
				flag = true;
			}
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
