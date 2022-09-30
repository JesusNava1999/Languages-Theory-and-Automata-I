#ifndef automata_h
#define automata_h

#include <stddef.h>
#include <string>
#include <set>
#include <map>

using namespace std;

class automata {
	unsigned q0, q1, q2, q3;
	
	typedef map<char, unsigned> event;
	typedef multimap<unsigned, event> state;
	
	unsigned init;
	state delta;
	set<unsigned> finalStates;
	
	event e_1;
	event e_2;
	event e_3;
	event e_4;
	event e_5;
	event e_6;
	event e_7;
	event e_8;

public:
	automata();
	
	bool test(string);
	
	void print();
	
	unsigned transition(unsigned, char, multimap<unsigned, map<char, unsigned>>);
	
	multimap<unsigned, map<char, unsigned>> Delta();

};

#endif
