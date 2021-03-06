#include "Adherent.h"
#include "Bibliotheque.h"
#include "Livre.h"

Adherent::Adherent(const string& n, const string& p, const string& a,  int num, Bibliotheque* b,  int nb) {
    nom = n;
    prenom = p;
    adresse = a;
    numero = num;
    bibliotheque = b;
    nbEmprunts = nb;
    nbLivres = 0;
    tab = new Livre*[nbEmprunts];
}

void Adherent::emprunter(const string& c){
    try{
        Livre* livre = this->getBibliotheque()->trouverLivre(c);
        if (livre->getEtat() == "Prêté"){
            cout << "Ce livre est déjà emprunté !" << endl;
        }
        else {
            if (nbEmprunts == nbLivres) {
                cout << "Vous avez atteint votre nombre maximum d'emprunts !" << endl;
            }
            else {
                livre->setEtat("Prêté");
                tab[nbLivres] = livre;
                nbLivres = nbLivres + 1;
            }
        }
    }
    catch (...) {
        cout << "Livre non trouvé" << endl;
    }

};

void Adherent::rendre(const string& c){
    Livre* livre = this->getBibliotheque()->trouverLivre(c);
    bool trouve = false;
    for (int i = 0; i < nbLivres; ++i) {
        if (!trouve){
            if (c == ((*tab[i]).getCode())){
                if (this->getBibliotheque()->getCode() == livre->getProprietaire()->getCode()) {
                    tab[i]->setEtat("Libre");
                }
                else {
                    tab[i]->setEtat("Emprunté");
                }
                tab[i] = tab[i+1];
                trouve = true;
            }
        }
        else {
            tab[i] = tab[i+1];
        }
    }
    nbLivres = nbLivres - 1;
}

void Adherent::afficherLivres() {
    for(int i = 0; i < nbLivres; ++i)
    {
        cout << *tab[i] << endl;
    }
}

ostream& operator<<(ostream& out, Adherent &adherent) {
    return out << "Nom = " << adherent.nom << " ; Prénom = " << adherent.prenom << " ; Adresse = " << adherent.adresse << " ; Numéro = " << adherent.numero << " ; Bibliothèque = " << adherent.bibliotheque->getNom() << " ; Nombre d'emprunts = " << adherent.nbEmprunts;
}

Adherent::~Adherent(){
    delete [] tab ;
}

