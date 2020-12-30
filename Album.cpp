#include "Album.h"

Album::Album(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, Bibliotheque* b, const string& illu) :
        Livre(c, t, a, e, i, p, et, b) {
    illustration = illu;
};

void Album::affiche() {
    Livre::affiche();
    cout << " ; Illustration = " << illustration << endl;
}
