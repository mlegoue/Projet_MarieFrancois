#ifndef PROJETC__MARIEFRANCOIS_PIECETHEATRE_H
#define PROJETC__MARIEFRANCOIS_PIECETHEATRE_H

#include <iostream>
using namespace std;
#include "Livre.h"

class PieceTheatre : public Livre {
private :
    string siecle;

public:
    PieceTheatre(const string &code, const string &titre, const string &auteur, const string &editeur, int ISBN, const string &publicconcerne, const string &etat, Bibliotheque* proprietaire, const string &siecle);


    string getSiecle() {
        return siecle;
    }

    void setSiecle(const string& siecle) {
        this->siecle = siecle;
    }

    string getCategorie() {
        return "Pièce de théâtre";
    }

    ostream& affiche(ostream& out);

    string getAttributSpe() {
        return siecle;
    }

};

#endif //PROJETC__MARIEFRANCOIS_PIECETHEATRE_H
