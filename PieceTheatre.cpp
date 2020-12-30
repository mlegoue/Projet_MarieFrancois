#include "PieceTheatre.h"

PieceTheatre::PieceTheatre(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, const Bibliotheque* b, int s) :
        Livre(c, t, a, e, i, p, et, b) {
    siecle = s;
};

