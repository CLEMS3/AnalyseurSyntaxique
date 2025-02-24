#include <iostream>
using namespace std;
#include "symbole.h"
#include "automate.h"

class State {
public:
    State();
    State(string s);
    virtual ~State();
    virtual void transition(Automate* automate, Symbole* s) = 0;
    virtual int state() = 0;
protected:
    string nomEtat;
};

class State0 : public State {
public:
    State0();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};

class State1 : public State {
public:
    State1();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};

class State2 : public State {
public:
    State2();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};

class State3 : public State {
public:
    State3();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};

class State4 : public State {
public:
    State4();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};

class State5 : public State {
public:
    State5();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};

class State6 : public State {
public:
    State6();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};

class State7 : public State {  
public:
    State7();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};

class State8 : public State {
public:
    State8();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};

class State9 : public State {
public:
    State9();
    void transition(Automate* automate, Symbole* s) override;
    int state() override;
protected:
    int valeur;
};