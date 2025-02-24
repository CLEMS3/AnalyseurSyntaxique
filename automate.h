#pragma once

#include <string>
#include <stack>
#include "lexer.h"
#include "symbole.h"

class Automate {
public:
    Automate();
    virtual ~Automate();
    void setState(State* state);
    void decalage(Symbole* s, State* state);
    void reduction(int n, Symbole* s);
    void lancer(string chaine);
protected:
    stack<Symbole*> symboles;
    stack<State*> etats;
    Lexer* lexer;
}