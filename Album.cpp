#include "Album.h"

Album::Album(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, const Bibliotheque* b, const string& illu) :
        Livre(c, t, a, e, i, p, et, b) {
    illustration = illu;
};