#ifndef PROJETC__MARIEFRANCOIS_BANDEDESSINEE_H
#define PROJETC__MARIEFRANCOIS_BANDEDESSINEE_H

#include <iostream>
using namespace std;
#include "Livre.h"

class BandeDessinee : public Livre {
private :
    string dessinateur;

public:
    BandeDessinee(const string &code, const string &titre, const string &auteur, const string &editeur, int ISBN, const string &publicconcerne, const string &etat, const Bibliotheque &proprietaire, const string &dessinateur);


    string getDessinateur() {
        return dessinateur;
    }

    void setDessinateur(string dessinateur) {
        this->dessinateur = dessinateur;
    }

    string getCategorie() {
        return "Bande Dessinée";
    }

};


#endif //PROJETC__MARIEFRANCOIS_BANDEDESSINEE_H
