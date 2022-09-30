#ifndef automata_h
#define automata_h

#include <stddef.h>
#include <string>
#include <set>
#include <map>

using namespace std;

class automata {
	unsigned q0, q1, q2, q3;
  unsigned finalState;
  unsigned init;
	
	typedef map<char, unsigned> event;
	typedef map<unsigned, event> state;	
	
	state delta;
	

public:
	automata();
	
	bool test(string);
	
	void print();
	
	unsigned transition(unsigned, char, map<unsigned, map<char, unsigned>>);
	
	map<unsigned, map<char, unsigned>> Delta();

};

#endif
