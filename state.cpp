#include "state.h"
#include "symbole.h"
#include <iostream>

State::State() {}
State::~State() {}
State::State(string s) { nomEtat = s; }
State0::State0() : State("E0") {}
State1::State1() : State("E1") {}
State2::State2() : State("E2") {}
State3::State3() : State("E3") {}
State4::State4() : State("E4") {}
State5::State5() : State("E5") {}
State6::State6() : State("E6") {}
State7::State7() : State("E7") {}
State8::State8() : State("E8") {}
State9::State9() : State("E9") {}

bool State0::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State0 avec symbole : " << *s << std::endl;
    switch (*s) {
        case INT:
            std::cout << "➡️ Décalage vers State3" << std::endl;
            automate.decalage(s, new State3());
            break;
        case OPENPAR:
            std::cout << "➡️ Décalage vers State2" << std::endl;
            automate.decalage(s, new State2());
            break;
        case EXPR:
            std::cout << "➡️ Décalage vers State1" << std::endl;
            automate.decalage(s, new State1());
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State0 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool State1::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State1 avec symbole : " << *s << std::endl;
    switch (*s) {
        case PLUS:
            std::cout << "➡️ Décalage vers State4" << std::endl;
            automate.decalage(s, new State4());
            break;
        case MULT:
            std::cout << "➡️ Décalage vers State5" << std::endl;
            automate.decalage(s, new State5());
            break;
        case FIN:
            return false;
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State1 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool State2::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State2 avec symbole : " << *s << std::endl;
    switch (*s) {
        case INT:
            std::cout << "➡️ Décalage vers State3" << std::endl;
            automate.decalage(s, new State3());
            break;
        case OPENPAR:
            std::cout << "➡️ Décalage vers State2" << std::endl;
            automate.decalage(s, new State2());
            break;
        case EXPR:
            std::cout << "➡️ Décalage vers State6" << std::endl;
            automate.decalage(s, new State6());
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State2 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool State3::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State3 avec symbole : " << *s << std::endl;
    switch (*s) {
        case PLUS:
            std::cout << "⬅️ Réduction Plus" << std::endl;
            automate.reduction(1, new Plus());
            break;
        case MULT:
            std::cout << "⬅️ Réduction Mult" << std::endl;
            automate.reduction(1, new Mult());
            break;
        case CLOSEPAR:
            std::cout << "⬅️ Réduction Closepar" << std::endl;
            automate.reduction(1, new Closepar());
            break;
        case FIN:
            std::cout << "⬅️ Réduction Fin" << std::endl;
            automate.reduction(1, new Fin());
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State3 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool State4::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State4 avec symbole : " << *s << std::endl;
    switch (*s) {
        case INT:
            std::cout << "➡️ Décalage vers State3" << std::endl;
            automate.decalage(s, new State3());
            break;
        case OPENPAR:
            std::cout << "➡️ Décalage vers State2" << std::endl;
            automate.decalage(s, new State2());
            break;
        case EXPR:
            std::cout << "➡️ Décalage vers State7" << std::endl;
            automate.decalage(s, new State7());
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State4 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool State5::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State5 avec symbole : " << *s << std::endl;
    switch (*s) {
        case INT:
            std::cout << "➡️ Décalage vers State3" << std::endl;
            automate.decalage(s, new State3());
            break;
        case OPENPAR:
            std::cout << "➡️ Décalage vers State2" << std::endl;
            automate.decalage(s, new State2());
            break;
        case EXPR:
            std::cout << "➡️ Décalage vers State8" << std::endl;
            automate.decalage(s, new State8());
            break;
        case MULT:
            std::cout << "➡️ Décalage vers State5" << std::endl;
            automate.decalage(s, new State5());
            break;
        case FIN:
            std::cout << "⬅️ Réduction Fin" << std::endl;
            automate.reduction(3, new Fin());
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State5 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool State6::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State6 avec symbole : " << *s << std::endl;
    switch (*s) {
        case PLUS:
            std::cout << "➡️ Décalage vers State4" << std::endl;
            automate.decalage(s, new State4());
            break;
        case MULT:
            std::cout << "➡️ Décalage vers State5" << std::endl;
            automate.decalage(s, new State5());
            break;
        case CLOSEPAR:
            std::cout << "➡️ Décalage vers State9" << std::endl;
            automate.decalage(s, new State9());
            break;
        case INT:
            std::cout << "➡️ Décalage vers State3" << std::endl;
            automate.decalage(s, new State3());
            break;
        case EXPR:
            std::cout << "➡️ Décalage vers State5" << std::endl;  // Nouveau
            automate.decalage(s, new State5());
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State6 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool State7::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State7 avec symbole : " << *s << std::endl;
    switch (*s) {
        case PLUS:
            std::cout << "⬅️ Réduction Plus" << std::endl;
            automate.reduction(3, new Plus());
            break;
        case MULT:
            std::cout << "➡️ Décalage vers State5" << std::endl;
            automate.decalage(s, new State5());
            break;
        case CLOSEPAR:
            std::cout << "⬅️ Réduction Closepar" << std::endl;
            automate.reduction(3, new Closepar());
            break;
        case FIN:
            std::cout << "⬅️ Réduction Fin" << std::endl;
            automate.reduction(3, new Fin());
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State7 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool State8::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State8 avec symbole : " << *s << std::endl;
    switch (*s) {
        case PLUS:
            std::cout << "⬅️ Réduction Plus" << std::endl;
            automate.reduction(3, new Plus());
            break;
        case MULT:
            std::cout << "⬅️ Réduction Mult" << std::endl;
            automate.reduction(3, new Mult());
            break;
        case CLOSEPAR:
            std::cout << "⬅️ Réduction Closepar" << std::endl;
            automate.reduction(3, new Closepar());
            break;
        case FIN:
            std::cout << "⬅️ Réduction Fin" << std::endl;
            automate.reduction(3, new Fin());
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State8 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}

bool State9::transition(Automate& automate, Symbole* s) {
    std::cout << "📌 State9 avec symbole : " << *s << std::endl;
    switch (*s) {
        case PLUS:
            std::cout << "⬅️ Réduction Plus" << std::endl;
            automate.reduction(3, new Plus());
            break;
        case MULT:
            std::cout << "⬅️ Réduction Mult" << std::endl;
            automate.reduction(3, new Mult());
            break;
        case CLOSEPAR:
            std::cout << "⬅️ Réduction Closepar" << std::endl;
            automate.reduction(3, new Closepar());
            break;
        case FIN:
            std::cout << "⬅️ Réduction Fin" << std::endl;
            automate.reduction(3, new Fin());
            break;
        default:
            std::cout << "❌ Symbole non reconnu dans State9 : " << *s << std::endl;
            automate.decalage(new Symbole(ERREUR), NULL);
            return false;
    }
    return true;
}