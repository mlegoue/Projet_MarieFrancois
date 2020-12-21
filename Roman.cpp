#include "Roman.h"

Roman::Roman(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, const Bibliotheque& b, const string& g) :
        Livre(c, t, a, e, i, p, et, b) {
    genre = g;
};