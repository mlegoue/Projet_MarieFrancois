#include "RecueilPoesie.h"

RecueilPoesie::RecueilPoesie(const string& c, const string& t, const string& a,  const string& e,  int i,  const string& p,  const string& et, Bibliotheque* b, const string& indic) :
        Livre(c, t, a, e, i, p, et, b) {
    indicateur = indic;
};

void RecueilPoesie::affiche() {
    Livre::affiche();
    cout << " ; Indicateur = " << indicateur << endl;
}
