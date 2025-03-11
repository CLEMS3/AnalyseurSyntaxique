#include "lexer.h"
#include <iostream>

Symbole * Lexer::Consulter() {
   if (!tampon) {

      if (tete==flux.length())
         tampon = new Symbole(FIN);
      else
      {
         std::cout << "🔍 Lecture du caractère : '" << flux[tete] << "'" << std::endl;
         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR);
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR);
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT);
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS);
               tete++;
               break;
            default:
               if (flux[tete]<='9' && flux[tete]>='0') {
                  int resultat = flux[tete]-'0';
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  std::cout << "🔢 Nombre détecté : " << resultat << std::endl;
                  tampon = new Entier(resultat);
               }
               else {
                  std::cout << "❌ Caractère inconnu détecté : '" << flux[tete] << "'" << std::endl;
                  tampon = new Symbole(ERREUR);
               }
         }
      }
   }
   return tampon;
}

void Lexer::Avancer() {
   tampon = nullptr;
}

void Lexer::Reculer() {
   if (tete>0) tete--;
}
