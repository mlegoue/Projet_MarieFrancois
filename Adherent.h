#ifndef PROJETC__MARIEFRANCOIS_ADHERENT_H
#define PROJETC__MARIEFRANCOIS_ADHERENT_H

#include <iostream>
using namespace std;

#include "Bibliotheque.h"

class Adherent {

private:
    string nom;
    string prenom;
    string adresse;
    int numero;
    Bibliotheque bibliotheque;
    int nbEmprunts;
    Livre* tab[100];
    int nbLivre;

public:
    Adherent(const string &nom, const string &prenom, const string &adresse, int numero, const Bibliotheque &bibliotheque, int nbEmprunts, Livre* tab[100] = {
            nullptr});

    string getNom() {
        return nom;
    }

    string getPrenom() {
        return prenom;
    }

    string getAdresse() {
        return adresse;
    }

    int getNumero() {
        return this->numero;
    }

    Bibliotheque getBibliotheque() {
        return bibliotheque;
    }

    int getNbEmprunts() {
        return this->nbEmprunts;
    }

    void setNom(string nom) {
        this->nom = nom;
    }

    void setTitre(string prenom) {
        this->prenom = prenom;
    }

    void setAdresse(string adresse) {
        this->adresse = adresse;
    }

    void setNumero(int numero) {
        this->numero = numero;
    }

    void setBibliotheque(Bibliotheque bibliotheque) {
        this->bibliotheque = bibliotheque;
    }

    void setNbEmprunts(int nbEmprunts) {
        this->nbEmprunts = nbEmprunts;
    }


};

#endif //PROJETC__MARIEFRANCOIS_ADHERENT_H
