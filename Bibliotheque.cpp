#include "Bibliotheque.h"
#include "Livre.h"

#include <iostream>
using namespace std;

Bibliotheque::Bibliotheque(const string& n, const string& a, const string& c) {
    nom = n;
    adresse = a;
    code = c;
    nbLivre = 0;
    lengthL = 10;
    tab = new Livre*[10];
}

void Bibliotheque::ajoutLivre(Livre* livre) {
    if(nbLivre >= lengthL){
        this->changeTab(lengthL + 10);
    }
    tab[nbLivre] = livre;
    nbLivre = nbLivre + 1;
}

void Bibliotheque::afficherLivres() {
    for(int i = 0; i < nbLivre; ++i)
    {
        cout << *tab[i] << endl;
    }
}

void Bibliotheque::afficherParCategorie(const string& categorie) {
    for(int i = 0; i < nbLivre; ++i)
    {
        if ((*tab[i]).getCategorie() == categorie) {
            cout << *tab[i] << endl;
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
    if (trouve) {
        nbLivre = nbLivre - 1;
    }
    if(nbLivre <= lengthL - 10){
        this->changeTab(lengthL - 10);
    }
}

Livre* Bibliotheque::trouverLivre(const string &c) {
    for (int i = 0; i < nbLivre; ++i) {
        if (c == ((*tab[i]).getCode())) {
            return tab[i];
        }
    }
    throw 0;
}

Livre* Bibliotheque::trouverLivre(int isbn) {
    for (int i = 0; i < nbLivre; ++i) {
        if (isbn == ((*tab[i]).getISBN())) {
            return tab[i];
        }
    }
    throw 0; // livre non trouvé
}

void Bibliotheque::emprunter(int i, Bibliotheque* biblio) {
    try {
        Livre* livre = biblio->trouverLivre(i);
        if (livre->getEtat() == "Libre") {
            biblio->supprimerLivre(livre->getCode());
            this->ajoutLivre(livre);
            livre->setEtat("Emprunté");
        }
        else {
            cout << "Ce livre est emprunté par un adhérent !" << endl;
        }
    }
    catch (...) {
        cout << "Exception : livre non trouvé" << endl ;
    }

}

void Bibliotheque::rendre() {
    for (int i = 0; i < nbLivre; ++i) {
        if ((*tab[i]).getEtat() == "Emprunté") {
            (tab[i])->setEtat("Libre");
            Bibliotheque* proprio = (*tab[i]).getProprietaire();
            proprio->ajoutLivre(tab[i]);
            this->supprimerLivre((*tab[i]).getCode());
        }
    }
}

void Bibliotheque::changeTab(int newL){
    auto** newTab = new Livre*[newL];
    for(int i=0; i<nbLivre; i++){
        newTab[i] = tab[i];
    }
    lengthL = newL;
    delete tab;
    tab = newTab;
}


ostream& operator<<(ostream &out, Bibliotheque &biblio) {
    return out << "Nom = " << biblio.nom << " ; Adresse = " << biblio.adresse << " ; Code = " << biblio.code;
}

Bibliotheque::~Bibliotheque(){
    if(!tab)
        delete [] tab ;
}

