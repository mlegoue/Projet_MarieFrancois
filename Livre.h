#ifndef PROJETC__MARIEFRANCOIS_LIVRE_H
#define PROJETC__MARIEFRANCOIS_LIVRE_H

#include <iostream>
#include "Bibliotheque.h"

using namespace std;



class Livre {

private:
    string code;
    string titre;
    string auteur;
    string editeur;
    int ISBN;
    string publicconcerne; //public est reservé par C++
    string etat;
    Bibliotheque proprietaire;


public:
    Livre(const string &code, const string &titre, const string &auteur, const string &editeur, int ISBN, const string &publicconcerne, const string &etat, const Bibliotheque &proprietaire);

    string getCode() {
        return code;
    }

    string getTitre() {
        return titre;
    }

    string getAuteur() {
        return auteur;
    }

    string getEditeur() {
        return editeur;
    }

    int getISBN() {
        return this->ISBN;
    }

    string getPublicConcerne() {
        return publicconcerne;
    }

    string getEtat() {
        return etat;
    }

    Bibliotheque getProprietaire() {
        return proprietaire;
    }



    void setCode(string code) {
        this->code = code;
    }

    void setTitre(string titre) {
        this->titre = titre;
    }

    void setAuteur(string auteur) {
        this->auteur = auteur;
    }

    void setEditeur(string editeur) {
        this->editeur = editeur;
    }

    void setISBN(int ISBN) {
        this->ISBN = ISBN;
    }

    void setPublicConcerne(string publicconcerne) {
        this->publicconcerne = publicconcerne;
    }

    void setEtat(string etat) {
        this->etat = etat;
    }

    void setProprietaire(const Bibliotheque &proprietaire) {
        this->proprietaire = proprietaire;
    }

    virtual string getCategorie() {
        return "Livre";
    }



};


#endif //PROJETC__MARIEFRANCOIS_LIVRE_H
