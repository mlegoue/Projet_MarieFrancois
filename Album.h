#ifndef PROJETC__MARIEFRANCOIS_ALBUM_H
#define PROJETC__MARIEFRANCOIS_ALBUM_H

#include <iostream>
using namespace std;
#include "Livre.h"

class Album : public Livre {
private :
    string illustration;

public:
    Album(const string &code, const string &titre, const string &auteur, const string &editeur, int ISBN, const string &publicconcerne, const string &etat, Bibliotheque* proprietaire, const string &illustration);


    string getIllustration() {
        return illustration;
    }

    void setIllustration(string illustration) {
        this->illustration = illustration;
    }

    string getCategorie() {
        return "Album";
    }

    ostream& affiche(ostream& out);

    string getAttributSpe() {
        return illustration;
    }

};

#endif //PROJETC__MARIEFRANCOIS_ALBUM_H
