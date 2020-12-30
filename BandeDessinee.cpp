#include "BandeDessinee.h"

BandeDessinee::BandeDessinee(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, Bibliotheque* b, const string& d) :
                             Livre(c, t, a, e, i, p, et, b) {
    dessinateur = d;
};

void BandeDessinee::affiche() {
    Livre::affiche();
    cout << " ; Dessinateur = " << dessinateur << endl;
}

