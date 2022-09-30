#include <iostream>
#include <ctime>
#include <map>
#include <string>
#include <set>
#include "automata.h"

void cleanWord(char *, int);

using namespace std;

int main()
{
    automata A;
    cout << "Automata: " << endl;
    A.print();
    return 0;
}
