#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      virtual int obtenirValeur();
   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      virtual int obtenirValeur();
   protected:
      int valeur;
};

class Plus : public Symbole {
   public:
      Plus() : Symbole(PLUS) { }
      ~Plus() { }
      virtual void Affiche();
};

class Mult : public Symbole {
   public:
      Mult() : Symbole(MULT) { }
      ~Mult() { }
      virtual void Affiche();
};

class Openpar : public Symbole {
   public:
      Openpar() : Symbole(OPENPAR) { }
      ~Openpar() { }
      virtual void Affiche();
};

class Closepar : public Symbole {
   public:
      Closepar() : Symbole(CLOSEPAR) { }
      ~Closepar() { }
      virtual void Affiche();
};

class Expression : public Symbole {
   public:
      Expression(int v) : Symbole(EXPR), valeur(v) { }
      ~Expression() { }
      virtual void Affiche();
      virtual int obtenirValeur();
   protected:
      int valeur;
};

class Fin : public Symbole {
   public:
      Fin() : Symbole(FIN) { }
      ~Fin() { }
      virtual void Affiche();
};

class Erreur : public Symbole {
   public:
      Erreur() : Symbole(ERREUR) { }
      ~Erreur() { }
      virtual void Affiche();
};

