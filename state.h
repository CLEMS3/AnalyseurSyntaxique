#include <iostream>
using namespace std;
#include "Automate.h"

class Automate;

class State {
public:
    State();
    virtual ~State();
    virtual void transition(Automate* automate, Symbole* s) = 0;
}

class State1 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

class State2 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

class State3 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

class State4 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

class State5 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

class State6 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

class State7 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

class State8 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

class State9 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

class State10 : public State {
    void transition(Automate* automate, Symbole* s) override;
}

