#ifndef PROJETC_MARIEFRANCOIS_BIBLIOTHEQUE_H
#define PROJETC_MARIEFRANCOIS_BIBLIOTHEQUE_H

class Livre;
#include <iostream>
using namespace std;

class Bibliotheque {

private:
    string nom;
    string adresse;
    string code;
    Livre** tab;
    int nbLivre;
    int lengthL;
    void changeTab(int newL);

public:
    Bibliotheque(const string &nom = "Bibliothèque", const string &adresse = "", const string &code = "000");

    string getNom() {
        return nom;
    }

    string getAdresse() {
        return adresse;
    }

    string getCode() {
        return code;
    }

    Livre** getLivres() {
        return tab;
    }

    int getNbLivre() {
        return nbLivre;
    }

    void setNom(string nom) {
        this->nom = nom;
    }

    void setAdresse(string adresse) {
        this->adresse = adresse;
    }

    void setCode(string code) {
        this->code = code;
    }

    void ajoutLivre(Livre* livre);

    void afficherLivres();

    void afficherParCategorie(const string &categorie);

    void supprimerLivre(const string &code);

    Livre* trouverLivre(const string &code);

    Livre* trouverLivre(int ISBN);

    void emprunter(int ISBN, Bibliotheque* bibliotheque);

    void rendre();

    friend ostream& operator<<(ostream &out, Bibliotheque& biblio);
};


#endif //PROJETC_MARIEFRANCOIS_BIBLIOTHEQUE_H
