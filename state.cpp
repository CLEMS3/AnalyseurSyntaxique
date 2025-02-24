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

void State0::transition(Automate& automate, Symbole* s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new State3());
            break;
        case OPENPAR:
            automate.decalage(s, new State2());
            break;
        case EXPR:
            automate.decalage(s, new State1());
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return;
    }
}

void State1::transition(Automate& automate, Symbole* s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new State4());
            break;
        case MULT:
            automate.decalage(s, new State5());
            break;
        case FIN:
            return;
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return;
    }
}

void State2::transition(Automate& automate, Symbole* s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new State3());
            break;
        case OPENPAR:
            automate.decalage(s, new State2());
            break;
        case EXPR:
            automate.decalage(s, new State6());
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return;
    }
}

void State4::transition(Automate& automate, Symbole* s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new State3());
            break;
        case OPENPAR:
            automate.decalage(s, new State2());
            break;
        case EXPR:
            automate.decalage(s, new State7());
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return;
    }
}

void State5::transition(Automate& automate, Symbole* s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new State3());
            break;
        case OPENPAR:
            automate.decalage(s, new State2());
            break;
        case EXPR:
            automate.decalage(s, new State8());
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return;
    }
}

void State6::transition(Automate& automate, Symbole* s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new State4());
            break;
        case MULT:
            automate.decalage(s, new State5());
            break;
        case CLOSEPAR:
            automate.decalage(s, new State9());
            break;
        default:
            automate.decalage(new Symbole(ERREUR), NULL);
            return;
    }
}