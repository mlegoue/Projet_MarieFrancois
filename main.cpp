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

Bibliotheque* listeBiblio[100];
int nbBiblio = 0;
Adherent* listeAdherent[100];
int nbAdherent = 0;


void load_fixtures();
void menu();
void menuBiblio();
void menuAdherent();
void menuCreer();
void creerLivre(Bibliotheque* biblio);


int main() {
    cout << endl;
    cout << "Bienvenue sur le gestionnaire de bibliothèques" << endl;
    load_fixtures();
    menu();
    return 0;
}

void load_fixtures() {
    auto* biblio = new Bibliotheque("Bibliotheque 1", "Marseille", "1234");
    BandeDessinee tintin("0000", "Les aventures de Tintin", "Hergé", "Le petit Vingtième", 0000, "Tout public", "libre", biblio, "Hergé");
    RecueilPoesie recueil("2345", "Recueil", "Baudelaire", "Jsp", 2345, "Adulte", "Libre", biblio, "vers");
    Roman roman("3456", "Roman", "Qqn", "Jsp", 3456, "Adulte", "Libre", biblio, "Policier");
    PieceTheatre theatre("4567", "Theatre", "Qqn d'autre", "Jsp", 4567, "Jeunesse", "Libre", biblio, "20");
    Album album("5678", "Album", "Un random", "Jsp", 4567, "Ados", "Libre", biblio, "Photo");
    biblio->ajoutLivre(&tintin);
    biblio->ajoutLivre(&recueil);
    biblio->ajoutLivre(&roman);
    biblio->ajoutLivre(&theatre);
    biblio->ajoutLivre(&album);
    Adherent moi("Le Goué", "Marie", "Marseille", 1234, biblio, 4);
    moi.emprunter("0000");
    moi.emprunter("2345");
    moi.emprunter("3456");
    moi.emprunter("5678");
    Adherent foder("Oder", "François", "Marseille", 2345, biblio, 2);
    moi.rendre("0000");
    auto* biblio2 = new Bibliotheque("Bibliotheque 2", "Marseille", "5678");
    BandeDessinee tintin2("00002", "Les aventures de Tintin2", "Hergé", "Le petit Vingtième", 00002, "Tout public", "Libre", biblio2, "Hergé");
    RecueilPoesie recueil2("23452", "Recueil2", "Baudelaire", "Jsp", 23452, "Adulte", "Libre", biblio2, "vers");
    Roman roman2("34562", "Roman2", "Qqn", "Jsp", 34562, "Adulte", "Libre", biblio2, "Policier");
    PieceTheatre theatre2("45672", "Theatre2", "Qqn d'autre", "Jsp", 45672, "Jeunesse", "Libre", biblio2, "20");
    Album album2("56782", "Album2", "Un random", "Jsp", 45672, "Ados", "Libre", biblio2, "Photo");
    biblio2->ajoutLivre(&tintin2);
    biblio2->ajoutLivre(&recueil2);
    biblio2->ajoutLivre(&roman2);
    biblio2->ajoutLivre(&theatre2);
    biblio2->ajoutLivre(&album2);
    biblio2->emprunter(0000, biblio);
    biblio2->rendre();
    listeBiblio[nbBiblio] = biblio;
    nbBiblio = nbBiblio + 1;
    listeBiblio[nbBiblio] = biblio2;
    nbBiblio = nbBiblio + 1;
    listeAdherent[nbAdherent] = &moi;
    nbAdherent = nbAdherent + 1;
    listeAdherent[nbAdherent] = &foder;
    nbAdherent = nbAdherent + 1;
    cout << biblio->getLivres()[0]->getAttributSpe() << endl;
}

void menu(){
    int choix = 0;
    cout << endl;
    cout << "=== Que voulez-vous faire ? ===" << endl;
    cout << "1) Gérer une bibliothèque" << endl;
    cout << "2) Gérer un adhérent" << endl;
    cout << "3) Créer une entité" << endl;
    cout << "1001) Enregistrer et quitter" << endl;

    cout << "Votre choix : ";
    cin >> choix;

    switch(choix){
        case 1:
            menuBiblio();
            break;
        case 2:
            menuAdherent();
            break;
        case 3:
            break;
        case 1001:
            break;
        default:
            cout << endl <<  "Choix invalide." << endl;
    }

}

template <typename Object>
Object* choose(Object** tab, int nb){
    int choix = 0;
    for (int i = 0; i < nb; ++i) {
        cout << i << ") ";
        (*tab[i]).affiche();
    }
    cout << "Votre choix : ";
    cin >> choix;

    return tab[choix];

}

void menuBiblio(){
    cout << endl;
    cout << "=== Laquelle ? ===" << endl;
    auto* biblio = choose<Bibliotheque>(listeBiblio, nbBiblio);
    int choix = 0;
    cout << endl;
    cout << "=== Que voulez-vous faire ? ===" << endl;
    cout << "0) Afficher" << endl;
    cout << "1) Ajouter un livre" << endl;
    cout << "2) Supprimer un livre" << endl;
    cout << "3) Emprunter à une autre bibliothèque" << endl;
    cout << "4) Rendre les livres" << endl;

    cout << "Votre choix : ";
    cin >> choix;


    switch(choix){
        case 0:
            biblio->affiche();
            biblio->afficherLivres();
            menu();
            break;
        case 1:
            creerLivre(biblio);
            menu();
            break;
        case 2: {
            cout << endl;
            cout << "=== Quel livre voulez-vous supprimer ? ===" << endl;
            auto *livre = choose<Livre>(biblio->getLivres(), biblio->getNbLivre());
            biblio->supprimerLivre(livre->getCode());
            menu();
            break;
        }
        case 3: {
            cout << endl;
            cout << "=== A quelle bibliothèque voulez-vous emprunter ? ===" << endl;
            auto* bibliotheque = choose<Bibliotheque>(listeBiblio, nbBiblio);
            cout << endl;
            cout << "=== Quel livre voulez-vous emprunter ? ===" << endl;
            auto* livre = choose<Livre>(bibliotheque->getLivres(), bibliotheque->getNbLivre());
            biblio->emprunter(livre->getISBN(), bibliotheque);
            menu();
            break;
        }
        case 4:
            biblio->rendre();
            menu();
            break;
        case 1001:
            break;
        default:
            cout << endl <<  "Choix invalide." << endl;
    }
}

void creerLivre(Bibliotheque* bibliotheque){
    int choix = 0;
    string code;
    string titre;
    string auteur;
    string editeur;
    string strISBN;
    string publicconcerne;
    string etat;
    cout << endl;
    cout << "=== Quelle catégorie ? ===" << endl;
    cout << "1) Album" << endl;
    cout << "2) Bande Dessinée" << endl;
    cout << "3) Pièce de théâtre" << endl;
    cout << "4) Recueil de Poésie" << endl;
    cout << "5) Roman" << endl;
    cout << "Votre choix :" << endl;
    cin >> choix;
    cout << "Code :" << endl;
    cin >> code;
    cout << "Titre :" << endl;
    cin >> titre;
    cout << "Auteur :" << endl;
    cin >> auteur;
    cout << "Editeur :" << endl;
    cin >> editeur;
    cout << "Public concerné :" << endl;
    cin >> publicconcerne;
    cout << "ISBN :" << endl;
    cin >> strISBN;
    int ISBN = std::stoi( strISBN );
    if (choix == 1){
        string illustration;
        cout << "Illustration :" << endl;
        cin >> illustration;
        Album album(code, titre, auteur, editeur, ISBN, publicconcerne, "libre", bibliotheque, illustration);
        bibliotheque->ajoutLivre(&album);
    }
    else if (choix == 2){
        string dessinateur;
        cout << "Dessinateur :" << endl;
        cin >> dessinateur;
        BandeDessinee bd(code, titre, auteur, editeur, ISBN, publicconcerne, "libre", bibliotheque, dessinateur);
        bibliotheque->ajoutLivre(&bd);
    }
    else if (choix == 3) {
        string siecle;
        cout << "Siècle :" << endl;
        cin >> siecle;
        PieceTheatre pt(code, titre, auteur, editeur, ISBN, publicconcerne, "libre", bibliotheque, siecle);
        bibliotheque->ajoutLivre(&pt);
    }
    else if (choix == 4) {
        string indicateur;
        cout << "Indicateur :" << endl;
        cin >> indicateur;
        RecueilPoesie rp(code, titre, auteur, editeur, ISBN, publicconcerne, "libre", bibliotheque, indicateur);
        bibliotheque->ajoutLivre(&rp);
    }
    else if (choix == 5) {
        string genre;
        cout << "Genre :" << endl;
        cin >> genre;
        Roman rom(code, titre, auteur, editeur, ISBN, publicconcerne, "libre", bibliotheque, genre);
        bibliotheque->ajoutLivre(&rom);
    }
    else {
        cout << endl << "Choix invalide." << endl;
    }
    menu();

}

void menuAdherent(){
    cout << endl;
    cout << "=== Lequel ? ===" << endl;
    auto* adherent = choose<Adherent>(listeAdherent, nbAdherent);
    int choix = 0;
    cout << endl;
    cout << "=== Que voulez-vous faire ? ===" << endl;
    cout << "0) Afficher" << endl;
    cout << "1) Ajouter un livre" << endl;
    cout << "2) Supprimer un livre" << endl;
    cout << "3) Emprunter à une autre bibliothèque" << endl;
    cout << "4) Rendre les livres" << endl;


}