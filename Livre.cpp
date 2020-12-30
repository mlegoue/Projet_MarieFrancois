#include "Livre.h"
#include "Bibliotheque.h"

#include <iostream>
using namespace std;

Livre::Livre(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, Bibliotheque* b) {
    code = c;
    titre = t;
    auteur = a;
    editeur = e;
    ISBN = i;
    publicconcerne = p;
    etat = et;
    proprietaire = b;
}

void Livre::affiche() {
    cout << "Code = " << code << " ; Titre = " << titre << " ; Auteur = " << auteur << " ; Éditeur = " << editeur << " ; ISBN = " << ISBN << " ; Public concerné = " << publicconcerne << " ; État = " << etat << " ; Propriétaire = " << proprietaire->getNom() << endl;
}
