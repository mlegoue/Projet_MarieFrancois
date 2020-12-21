#ifndef PROJETC__MARIEFRANCOIS_RECUEILPOESIE_H
#define PROJETC__MARIEFRANCOIS_RECUEILPOESIE_H

#include <iostream>
using namespace std;
#include "Livre.h"

class RecueilPoesie : public Livre {
private :
    string indicateur;

public:
    RecueilPoesie(const string &code, const string &titre, const string &auteur, const string &editeur, int ISBN, const string &publicconcerne, const string &etat, const Bibliotheque &proprietaire, const string &indicteur);


    string getIndicateur() {
        return indicateur;
    }

    void setIndicteur(string indicateur) {
        this->indicateur = indicateur;
    }

    string getCategorie() {
        return "Recueil de Poésie";
    }

};


#endif //PROJETC__MARIEFRANCOIS_RECUEILPOESIE_H
