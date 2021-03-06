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
#include "EM.cpp"

Bibliotheque* listeBiblio[100];
int nbBiblio = 0;
Adherent* listeAdherent[100];
int nbAdherent = 0;


void menu();
void menuBiblio();
void menuAdherent();
void menuCreer();
void creerLivre(Bibliotheque* biblio);
void choixAfficheCategorie(Bibliotheque* biblio);


int main() {
    cout << endl;
    cout << "Bienvenue sur le gestionnaire de bibliothèques" << endl;
    load(listeBiblio, &nbBiblio, listeAdherent, &nbAdherent);
    menu();
    return 0;
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
            menuCreer();
            break;
        case 1001:
            save(listeBiblio, &nbBiblio, listeAdherent, &nbAdherent);
            return;
        default:
            cout << endl <<  "Choix invalide." << endl;
    }

}

template <typename Object>
Object* choose(Object** tab, int nb){
    int choix = 0;
    for (int i = 0; i < nb; ++i) {
        cout << i << ") " << *tab[i] << endl;
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
    cout << "1) Afficher par categorie" << endl;
    cout << "2) Ajouter un livre" << endl;
    cout << "3) Supprimer un livre" << endl;
    cout << "4) Emprunter à une autre bibliothèque" << endl;
    cout << "5) Rendre les livres" << endl;

    cout << "Votre choix : ";
    cin >> choix;


    switch(choix){
        case 0:
            cout << *biblio << endl;
            biblio->afficherLivres();
            menu();
            break;
        case 1:
            choixAfficheCategorie(biblio);
            break;
        case 2:
            creerLivre(biblio);
            menu();
            break;
        case 3: {
            cout << endl;
            cout << "=== Quel livre voulez-vous supprimer ? ===" << endl;
            auto *livre = choose<Livre>(biblio->getLivres(), biblio->getNbLivre());
            biblio->supprimerLivre(livre->getCode());
            menu();
            break;
        }
        case 4: {
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
        case 5:
            biblio->rendre();
            menu();
            break;
        case 1001:
            break;
        default:
            cout << endl <<  "Choix invalide." << endl;
    }
}

void choixAfficheCategorie(Bibliotheque* bibliotheque){
    int choix = 0;
    cout << endl;
    cout << "=== Quelle catégorie ? ===" << endl;
    cout << "1) Album" << endl;
    cout << "2) Bande Dessinée" << endl;
    cout << "3) Pièce de théâtre" << endl;
    cout << "4) Recueil de Poésie" << endl;
    cout << "5) Roman" << endl;
    cout << "Votre choix : ";
    cin >> choix;
    if (choix == 1){
        bibliotheque->afficherParCategorie("Album");
    }
    else if (choix == 2){
        bibliotheque->afficherParCategorie("Bande Dessinée");
    }
    else if (choix == 3) {
        bibliotheque->afficherParCategorie("Pièce de théâtre");
    }
    else if (choix == 4) {
        bibliotheque->afficherParCategorie("Recueil de Poésie");
    }
    else if (choix == 5) {
        bibliotheque->afficherParCategorie("Roman");
    }
    else {
        cout << endl << "Choix invalide." << endl;
    }
    menu();

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
    getline(cin >> ws, titre);
    cout << "Auteur :" << endl;
    getline(cin >> ws, auteur);
    cout << "Editeur :" << endl;
    getline(cin >> ws, editeur);
    cout << "Public concerné :" << endl;
    getline(cin >> ws, publicconcerne);
    cout << "ISBN :" << endl;
    cin >> strISBN;
    int ISBN = std::stoi( strISBN );
    if (choix == 1){
        string illustration;
        cout << "Illustration :" << endl;
        cin >> illustration;
        auto* album = new Album(code, titre, auteur, editeur, ISBN, publicconcerne, "Libre", bibliotheque, illustration);
        bibliotheque->ajoutLivre(album);
    }
    else if (choix == 2){
        string dessinateur;
        cout << "Dessinateur :" << endl;
        cin >> dessinateur;
        auto* bd = new BandeDessinee(code, titre, auteur, editeur, ISBN, publicconcerne, "Libre", bibliotheque, dessinateur);
        bibliotheque->ajoutLivre(bd);
    }
    else if (choix == 3) {
        string siecle;
        cout << "Siècle :" << endl;
        cin >> siecle;
        auto* pt = new PieceTheatre(code, titre, auteur, editeur, ISBN, publicconcerne, "Libre", bibliotheque, siecle);
        bibliotheque->ajoutLivre(pt);
    }
    else if (choix == 4) {
        string indicateur;
        cout << "Indicateur :" << endl;
        cin >> indicateur;
        auto* rp = new RecueilPoesie(code, titre, auteur, editeur, ISBN, publicconcerne, "Libre", bibliotheque, indicateur);
        bibliotheque->ajoutLivre(rp);
    }
    else if (choix == 5) {
        string genre;
        cout << "Genre :" << endl;
        cin >> genre;
        auto* rom = new Roman(code, titre, auteur, editeur, ISBN, publicconcerne, "Libre", bibliotheque, genre);
        bibliotheque->ajoutLivre(rom);
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
    cout << "1) Emprunter un livre" << endl;
    cout << "2) Rendre un livre" << endl;

    cout << "Votre choix : ";
    cin >> choix;

    switch(choix){
        case 0:
            cout << *adherent << endl;
            adherent->afficherLivres();
            menu();
            break;
        case 1: {
            cout << endl;
            cout << "=== Quel livre voulez-vous emprunter ? ===" << endl;
            auto *livre = choose<Livre>(adherent->getBibliotheque()->getLivres(), adherent->getBibliotheque()->getNbLivre());
            adherent->emprunter(livre->getCode());
            menu();
            break;
        }
        case 2: {
            cout << endl;
            cout << "=== Quel livre voulez-vous rendre ? ===" << endl;
            auto *livre = choose<Livre>(adherent->getBibliotheque()->getLivres(), adherent->getBibliotheque()->getNbLivre());
            adherent->rendre(livre->getCode());
            menu();
            break;
        }
        case 1001:
            break;
        default:
            cout << endl <<  "Choix invalide." << endl;
    }
}

void menuCreer(){
    int choix = 0;
    cout << endl;
    cout << "=== Que voulez-vous créer ? ===" << endl;
    cout << "1) Bibliothèque" << endl;
    cout << "2) Adhérent" << endl;
    cout << "Votre choix :" << endl;
    cin >> choix;
    if (choix == 1){
        string nom;
        string adresse;
        string code;
        cout << "Nom :" << endl;
        getline(cin >> ws, nom);
        cout << "Adresse :" << endl;
        getline(cin >> ws, adresse);
        cout << "Code :" << endl;
        cin >> code;
        auto* bibli = new Bibliotheque(nom, adresse, code);
        listeBiblio[nbBiblio] = bibli;
        nbBiblio = nbBiblio + 1;
    }
    else if (choix == 2){
        string nom;
        string prenom;
        string adresse;
        int numero;
        Bibliotheque* b;
        int nbEmprunt;
        cout << "Nom :" << endl;
        getline(cin >> ws, nom);
        cout << "Prénom :" << endl;
        getline(cin >> ws, prenom);
        cout << "Adresse :" << endl;
        getline(cin >> ws, adresse);
        cout << "Numéro d'adhérent :" << endl;
        cin >> numero;
        cout << "Nombre d'emprunts :" << endl;
        cin >> nbEmprunt;
        cout << "Danq quelle bibliothèque est-il inscrit ?" << endl;
        auto* bibliotheque = choose<Bibliotheque>(listeBiblio, nbBiblio);
        auto* adherent = new Adherent(nom, prenom, adresse, numero, bibliotheque, nbEmprunt);
        listeAdherent[nbAdherent] = adherent;
        nbAdherent = nbAdherent + 1;
    }
    else {
        cout << endl << "Choix invalide." << endl;
    }
    menu();

}