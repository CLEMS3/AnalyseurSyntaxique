#include "state.h"
#include "symbole.h"
#include <iostream>


Automate::Automate() {
	State0 *debut = new State0();
	etats.push(debut);
}

Automate::~Automate() {
	while (!etats.empty()) {
		delete etats.top();
		etats.pop();
	}
	while (!symboles.empty()) {
		delete symboles.top();
		symboles.pop();
	}
	delete lexer;
}

void Automate::lancer(string chaine) {
	bool nextState = true;
	this->lexer = new Lexer(chaine);
	while (nextState) {
		Symbole *s = lexer->Consulter();
		lexer->Avancer();
		nextState = etats.top()->transition(*this, s);
	}
	if (*symboles.top() != ERREUR) {
		int resultat = symboles.top()->obtenirValeur();
		cout << resultat << endl;
	} else {
		cout << "Syntaxe non reconnue" << endl;
	}

	delete lexer;
}

void Automate::decalage(Symbole *s, State *e) {
	symboles.push(s);
	etats.push(e);
}

void Automate::reduction(int n, Symbole *s) {
	stack<Symbole *> symboleRetenu;

	for (int i = 0 ; i < n ; i++) {
		delete (etats.top());
	   etats.pop();  // On dépile l'état
	   symboleRetenu.push(symboles.top());
	   symboles.pop(); // On dépile le symbole
	}

	int val;

	if (n == 1) {
		val = symboleRetenu.top()->obtenirValeur();
	}
	if (n == 3) {
		if (*symboleRetenu.top() == OPENPAR) {
			symboleRetenu.pop();
			val = symboleRetenu.top()->obtenirValeur();
		}
		else {
			val = symboleRetenu.top()->obtenirValeur();
			symboleRetenu.pop();
			if (*symboleRetenu.top() == PLUS) {
				symboleRetenu.pop();
				val = val + symboleRetenu.top()->obtenirValeur();
			}
			else {
				symboleRetenu.pop();
				val = val * symboleRetenu.top()->obtenirValeur();
			}
		}
	}

	etats.top()->transition(*this, new Expression(val));
	// TODO ajouter au lexer
}