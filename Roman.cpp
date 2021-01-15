#include "Roman.h"

Roman::Roman(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, Bibliotheque* b, const string& g) :
        Livre(c, t, a, e, i, p, et, b) {
    genre = g;
};

ostream& Roman::affiche(ostream& out) {
    Livre::affiche(out);
    return out << " ; Genre = " << genre << endl;
}
