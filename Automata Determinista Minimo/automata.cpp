#include <iostream>
#include <stddef.h>
#include "automata.h"

automata::automata()
{
    // Valores de los estados
    q0 = 0;
    q1 = 1;
    q2 = 2;
    q3 = 3;
    q4 = 4;
    q5 = 5;
    q6 = 6;
    q7 = 7;
    // Definir estado inicial
    init = q0;
    // Definir los estados finales
    finalStates.insert(q1);
    finalStates.insert(q2);
    finalStates.insert(q5);
    finalStates.insert(q6);
    // Transiciones del estado q0
    delta[q0]['0'] = q1;
    for (int i = '1'; i <= '9'; i++)
    {
        delta[q0][((char)i)] = q2;
    }
    // Transiciones del estado q1
    delta[q1]['.'] = q3;
    delta[q1]['e'] = q4;
    delta[q1]['E'] = q4;
    // Transiciones del estado q2
    for (int i = '0'; i <= '9'; i++)
    {
        delta[q2][((char)i)] = q2;
    }
    delta[q2]['.'] = q3;
    delta[q2]['e'] = q4;
    delta[q2]['E'] = q4;
    // Transiciones del estado q3
    for (int i = '0'; i <= '9'; i++)
    {
        delta[q3][((char)i)] = q5;
    }
    // Transiciones del estado q4
    for (int i = '0'; i <= '9'; i++)
    {
        delta[q4][((char)i)] = q6;
    }
    delta[q4]['+'] = q7;
    delta[q4]['-'] = q7;
    // Transiciones del estado q5
    for (int i = '0'; i <= '9'; i++)
    {
        delta[q5][((char)i)] = q5;
    }
    delta[q5]['e'] = q4;
    delta[q5]['E'] = q4;
    // Transiciones del estado q6
    for (int i = '0'; i <= '9'; i++)
    {
        delta[q6][((char)i)] = q6;
    }
    // Transiciones del estado q7
    for (int i = '0'; i <= '9'; i++)
    {
        delta[q7][((char)i)] = q6;
    }
}

void automata::print()
{
    for (map<unsigned, event>::iterator it = delta.begin(); it != delta.end(); ++it)
    {
        for (map<char, unsigned>::iterator it_1 = it->second.begin(); it_1 != it->second.end(); ++it_1)
        {
            cout << "[" << it->first;
            cout << "," << it_1->first << "]: " << it_1->second << endl;
        }
    }

    cout << endl
         << "Final [ ";
    for (const auto &a : finalStates)
    {
        cout << a << " ";
    }
    cout << "]" << endl;
    //cout << endl << "Final [ "<< finalState << " ]" << endl;
}

unsigned automata::transition(unsigned currentState, char event, map<unsigned, map<char, unsigned>> delta)
{
    map<unsigned, map<char, unsigned>>::iterator it = delta.begin();
    unsigned aux;
    for (it = delta.begin(); it != delta.end(); ++it)
    {
        if (currentState == it->first)
        {
            for (map<char, unsigned>::iterator it_1 = it->second.begin(); it_1 != it->second.end(); ++it_1)
            {
                if (event == it_1->first)
                {
                    aux = it_1->second;
                }
            }
        }
    }
    return aux;
}

map<unsigned, map<char, unsigned>> automata::Delta()
{
    return delta;
}

bool automata::test(string word)
{
    bool flag = false;
    unsigned aux = init;
    if (word.length() > 0)
    {
        for (unsigned i = 0; i < word.length(); i++)
        {
            aux = transition(aux, word[i], delta);
        }
        for (const auto &a : finalStates)
        {
            if (aux == a)
            {
                flag = true;
            }
        }
        if (flag)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
