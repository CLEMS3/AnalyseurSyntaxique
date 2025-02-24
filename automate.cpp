#include "state.h"
#include <iostream>
#include <stdio.h>

Automate::Automate(string flux) {
	this->lexer = new Lexer(flux);
	State0 *debut = new State0();
	statestack.push(debut);
}

void Automate::run() {
	bool nextState = true;

	while (nextState) {
		Symbole *s = lexer->Consulter();
		lexer->Avancer();
		nextState = statestack.top()->transition(*this, s);
	}
	if (*symbolstack.top() != ERREUR) {
		int resultat = symbolstack.top()->getValue();
		cout << resultat << endl;
	else {
		cout << "Syntaxe non reconnue" << endl;
	}

void Automate::decalage(Symbole *s, State *e) {
	symbolstack.push(s);
	statestack.push(e);

for (int i = 0 ; i < n ; i++) {
	delete (statestack.top());
    statestack.pop();
    aEnlever.push(symbolstack.top());
    symbolstack.pop();
  }