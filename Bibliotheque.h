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
    Livre* tab[100];
    int nbLivre;

public:
    Bibliotheque(const string &nom = "Bibliothèque", const string &adresse = "", const string &code = "000", Livre* tab[100] = {nullptr});

    string getNom() {
        return nom;
    }

    string getAdresse() {
        return adresse;
    }

    string getCode() {
        return code;
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
};


#endif //PROJETC_MARIEFRANCOIS_BIBLIOTHEQUE_H
