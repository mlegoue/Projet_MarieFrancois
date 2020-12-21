#include "Bibliotheque.h"
#include "Livre.h"

#include <iostream>
using namespace std;

Bibliotheque::Bibliotheque(const string& n, const string& a, const string& c, Livre* tab[100] ) {
    nom = n;
    adresse = a;
    code = c;
    nbLivre = 0;
}

void Bibliotheque::ajoutLivre(Livre* livre) {
    tab[nbLivre] = livre;
    nbLivre = nbLivre + 1;
}

void Bibliotheque::afficherLivres() {
    for(int i = 0; i < nbLivre; ++i)
    {
        std::cout << "Code : " << (*tab[i]).getCode() << " Titre : " << (*tab[i]).getTitre() << std::endl;

    }
}

void Bibliotheque::afficherParCategorie(const string& categorie) {
    for(int i = 0; i < nbLivre; ++i)
    {
        if ((*tab[i]).getCategorie() == categorie) {
            std::cout << "Code : " << (*tab[i]).getCode() << " Titre : " << (*tab[i]).getTitre() << std::endl;
        }
    }
}

void Bibliotheque::supprimerLivre(const string &c) {
    bool trouve = false;
    for (int i = 0; i < nbLivre; ++i) {
        if (!trouve){
            if (c == ((*tab[i]).getCode())){
                trouve = true;
                tab[i] = tab[i+1];
            }
        }
        else {
            tab[i] = tab[i+1];
        }
    }
    nbLivre = nbLivre - 1;
}




