#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


#include "Bibliotheque.h"
#include "Livre.h"
#include "BandeDessinee.h"
#include "RecueilPoesie.h"
#include "Roman.h"
#include "PieceTheatre.h"
#include "Album.h"
#include "Adherent.h"

vector<Bibliotheque> bibliotheques;

void menuBiblio();
void menu();
void functionBiblio(Bibliotheque);

int main() {
    cout << "Projet C++ de François et Marie" << endl;
    Bibliotheque biblio("Bibliotheque 1", "Marseille", "1234");
    Livre livre("1234", "Coucou", "Moi", "Encore moi", 1234, "Tout public", "Libre", biblio);
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
    Adherent mlegoue("Le Goué", "Marie", "Marseille", 1234, biblio, 4);
    mlegoue.emprunter("2345");
    mlegoue.emprunter("3456");
    mlegoue.emprunter("5678");
    mlegoue.emprunter("4567");
    Adherent foder("Oder", "François", "Marseille", 2345, biblio, 2);
    foder.rendre("0000");
    Bibliotheque biblio2("Bibliotheque 2", "Marseille", "5678");
    Livre livre2("12342", "Coucou2", "Moi", "Encore moi", 12342, "Tout public", "Libre", biblio2);
    BandeDessinee tintin2("00002", "Les aventures de Tintin2", "Hergé", "Le petit Vingtième", 00002, "Tout public", "Libre", biblio2, "Hergé");
    RecueilPoesie recueil2("23452", "Recueil2", "Baudelaire", "Jsp", 23452, "Adulte", "Libre", biblio2, "vers");
    Roman roman2("34562", "Roman2", "Qqn", "Jsp", 34562, "Adulte", "Libre", biblio2, "Policier");
    PieceTheatre theatre2("45672", "Theatre2", "Qqn d'autre", "Jsp", 45672, "Jeunesse", "Libre", biblio2, 20);
    Album album2("56782", "Album2", "Un random", "Jsp", 45672, "Ados", "Libre", biblio2, "Photo");
    biblio2.ajoutLivre(&livre2);
    biblio2.ajoutLivre(&tintin2);
    biblio2.ajoutLivre(&recueil2);
    biblio2.ajoutLivre(&roman2);
    biblio2.ajoutLivre(&theatre2);
    biblio2.ajoutLivre(&album2);
    bibliotheques.push_back(biblio);
    bibliotheques.push_back(biblio2);


    //string const nomFichier("../Fichiers/Bibliotheque.txt"); //Visblement il s'execute dans le dossier cmalke-build-debug donc je le fais sortir
    //ofstream monFlux(nomFichier.c_str());
    //if(monFlux){
    //    monFlux << biblio.getNom() << " ; " << biblio.getAdresse() << " ; " << biblio.getCode() << endl;
    //    monFlux << biblio2.getNom() << " ; " << biblio2.getAdresse() << " ; " << biblio2.getCode() << endl;
    //}
    menu();
    return 0;
}

void menu(){
    int choix = 0;
        cout << "=== Qui êtes-vous ? ===" << endl;
        cout << "1) Une bibliothèque" << endl;
        cout << "2) Un adhérent" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        switch(choix) {
            case 1:
                menuBiblio();
                break;
            case 2:
                break;
            default:
                cout << endl << "Choix invalide" << endl;
        }
}

void fixtures() {
    Bibliotheque biblio("Bibliotheque 1", "Marseille", "1234");
    Livre livre("1234", "Coucou", "Moi", "Encore moi", 1234, "Tout public", "Libre", biblio);
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
    Adherent moi("Le Goué", "Marie", "Marseille", 1234, biblio, 4);
    moi.emprunter("0000");
    moi.emprunter("2345");
    moi.emprunter("3456");
    moi.emprunter("5678");
    moi.emprunter("4567");
    Adherent foder("Oder", "François", "Marseille", 2345, biblio, 2);
    moi.rendre("0000");
    Bibliotheque biblio2("Bibliotheque 2", "Marseille", "5678");
    Livre livre2("12342", "Coucou2", "Moi", "Encore moi", 12342, "Tout public", "Libre", biblio2);
    BandeDessinee tintin2("00002", "Les aventures de Tintin2", "Hergé", "Le petit Vingtième", 00002, "Tout public", "Libre", biblio2, "Hergé");
    RecueilPoesie recueil2("23452", "Recueil2", "Baudelaire", "Jsp", 23452, "Adulte", "Libre", biblio2, "vers");
    Roman roman2("34562", "Roman2", "Qqn", "Jsp", 34562, "Adulte", "Libre", biblio2, "Policier");
    PieceTheatre theatre2("45672", "Theatre2", "Qqn d'autre", "Jsp", 45672, "Jeunesse", "Libre", biblio2, 20);
    Album album2("56782", "Album2", "Un random", "Jsp", 45672, "Ados", "Libre", biblio2, "Photo");
    biblio2.ajoutLivre(&livre2);
    biblio2.ajoutLivre(&tintin2);
    biblio2.ajoutLivre(&recueil2);
    biblio2.ajoutLivre(&roman2);
    biblio2.ajoutLivre(&theatre2);
    biblio2.ajoutLivre(&album2);
    biblio2.emprunter(0000, &biblio);
    cout << "Bibilothèque 1" << endl;
    biblio.afficherLivres();
    cout << "Biblio 2" << endl;
    biblio2.afficherLivres();
    biblio2.rendre();
    cout << "Bibilothèque 1" << endl;
    biblio.afficherLivres();
    cout << "Biblio 2" << endl;
    biblio2.afficherLivres();
};

void menuBiblio() {
    int choix = 0;
    cout << "=== Quelle bibliothèque êtes-vous ? ===" << endl;
    for(int i = 0; i < bibliotheques.size() ; i++){
        cout << i << ") " ;
        bibliotheques[i].affiche();
    }
    cout << "Votre choix : ";
    cin >> choix;

    functionBiblio(bibliotheques[choix]);

}

void functionBiblio(Bibliotheque biblio) {
    int choix = 0;

    cout << "=== Que souhaitez-vous faire ? ===" << endl;
    cout << "1) Afficher tous mes livres" << endl;
    cout << "2) Afficher les livres d'une catégorie" << endl;
    cout << "3) Ajouter un livre" << endl;
    cout << "4) Supprimer un livre" << endl;
    cout << "5) Emprunter un livre à une autre bibliothèque" << endl;
    cout << "6) Rendre les livres" << endl;

    cout << "Votre choix : ";
    cin >> choix;
    string categorie;
    string code;

    switch(choix) {
        case 1:
            biblio.afficherLivres();
            break;
        case 2:
            cout << "Catégorie :" << endl;
            cin >> categorie;
            biblio.afficherParCategorie(categorie);
            break;
        case 3:
            cout << "Catégorie :" << endl;
            cin >> categorie;
            biblio.afficherParCategorie(categorie);
            break;
        case 4:
            cout << "Code :" << endl;
            cin >> code;
            biblio.supprimerLivre(code);
            break;
        default:
            cout << endl << "Choix invalide" << endl;
    }
}