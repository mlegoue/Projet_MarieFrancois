#ifndef PROJETC__MARIEFRANCOIS_ROMAN_H
#define PROJETC__MARIEFRANCOIS_ROMAN_H

#include <iostream>
using namespace std;
#include "Livre.h"

class Roman : public Livre {
private :
    string genre;

public:
    Roman(const string &code, const string &titre, const string &auteur, const string &editeur, int ISBN, const string &publicconcerne, const string &etat, const Bibliotheque &proprietaire, const string &genre);


    string getGenre() {
        return genre;
    }

    void setGenre(string genre) {
        this->genre = genre;
    }

    string getCategorie() {
        return "Roman";
    }

};

#endif //PROJETC__MARIEFRANCOIS_ROMAN_H
