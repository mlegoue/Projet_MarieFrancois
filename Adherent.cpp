#include "Adherent.h"
#include "Bibliotheque.h"

Adherent::Adherent(const string& n, const string& p, const string& a,  int num, const Bibliotheque& b,  int nb,  Livre* tab[100]) {
    nom = n;
    prenom = p;
    adresse = a;
    numero = num;
    bibliotheque = b;
    nbEmprunts = nb;
    nbLivre = 0;
}

