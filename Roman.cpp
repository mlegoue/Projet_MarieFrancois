#include "Roman.h"

Roman::Roman(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, Bibliotheque* b, const string& g) :
        Livre(c, t, a, e, i, p, et, b) {
    genre = g;
};

void Roman::affiche() {
    Livre::affiche();
    cout << " ; Genre = " << genre << endl;
}
