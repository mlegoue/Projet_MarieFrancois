#include <iostream>
using namespace std;

#include "Bibliotheque.h"
#include "Livre.h"
#include "BandeDessinee.h"
#include "RecueilPoesie.h"
#include "Roman.h"
#include "PieceTheatre.h"
#include "Album.h"
#include "Adherent.h"

int main() {
    Bibliotheque biblio("Bibliotheque 1", "Marseille", "1234");
    Livre livre("1234", "Coucou", "Moi", "Encore moi", 1234, "Tout public", "libre", biblio);
    BandeDessinee tintin("0000", "Les aventures de Tintin", "Hergé", "Le petit Vingtième", 0000, "Tout public", "libre", biblio, "Hergé");
    RecueilPoesie recueil("2345", "Recueil", "Baudelaire", "Jsp", 2345, "Adulte", "Libre", biblio, "vers");
    Roman roman("3456", "Roman", "Qqn", "Jsp", 3456, "Adulte", "Libre", biblio, "Policier");
    PieceTheatre theatre("4567", "Theatre", "Qqn d'autre", "Jsp", 4567, "Jeunesse", "Libre", biblio, 20);
    Album album("5678", "Album", "Un random", "Jsp", 4567, "Ados", "Libre", biblio, "Photo");
    biblio.ajoutLivre(&livre);
    biblio.ajoutLivre(&tintin);
    biblio.ajoutLivre(&recueil);
    biblio.ajoutLivre(&roman);
    biblio.ajoutLivre(&theatre);
    biblio.ajoutLivre(&album);
    biblio.supprimerLivre("4567");
    biblio.afficherLivres();
    Adherent moi("Le Goué", "Marie", "Marseille", 1234, biblio, 4);
    cout << moi.getBibliotheque().getNom() << endl;
    cout << album.getProprietaire().getNom() << endl;
}
