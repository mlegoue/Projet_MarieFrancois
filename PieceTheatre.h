#ifndef PROJETC__MARIEFRANCOIS_PIECETHEATRE_H
#define PROJETC__MARIEFRANCOIS_PIECETHEATRE_H

#include <iostream>
using namespace std;
#include "Livre.h"

class PieceTheatre : public Livre {
private :
    int siecle;

public:
    PieceTheatre(const string &code, const string &titre, const string &auteur, const string &editeur, int ISBN, const string &publicconcerne, const string &etat, const Bibliotheque &proprietaire, int siecle);


    int getGenre() {
        return siecle;
    }

    void setGenre(int siecle) {
        this->siecle = siecle;
    }

    string getCategorie() {
        return "Pièce de théatre";
    }

};

#endif //PROJETC__MARIEFRANCOIS_PIECETHEATRE_H
