#include "PieceTheatre.h"

PieceTheatre::PieceTheatre(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, Bibliotheque* b, const string& s) :
        Livre(c, t, a, e, i, p, et, b) {
    siecle = s;
};

ostream& PieceTheatre::affiche(ostream& out) {
    Livre::affiche(out);
    return out << " ; Siècle = " << siecle;
}
