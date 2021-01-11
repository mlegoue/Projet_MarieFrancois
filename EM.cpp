#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

#include "Bibliotheque.h"
#include "Livre.h"
#include "BandeDessinee.h"
#include "RecueilPoesie.h"
#include "Roman.h"
#include "PieceTheatre.h"
#include "Album.h"
#include "Adherent.h"

const string Afile_name = "adherents.txt";
const string Bfile_name = "bibliotheques.txt";
const string Lfile_name = "livres.txt";


void load(Bibliotheque** BIBLIO, int* nbBiblio, Adherent** ADHER, int* nbAdher){
    cout << "Chargement depuis les fichiers : " << Afile_name << ' ' << Bfile_name << ' ' << Lfile_name << endl;
    ifstream BfileR (Bfile_name);
    string Bname, Badress, Bcode, BnbL;
    map<string,Bibliotheque*> mapB;
    map<string, string*> livresOfB;
    map<string, int> nbLOfB;
    int nbB = 0;
    string* tab;
    string line;
    while(getline(BfileR, Bname)){
        getline(BfileR, Badress);
        getline(BfileR, Bcode);
        auto* b = new Bibliotheque(Bname, Badress, Bcode);
        mapB.insert({Bcode, b});
        getline(BfileR, BnbL);
        int nbL = stoi(BnbL);
        tab = new string[nbL];
        nbLOfB.insert({Bcode, nbL});
        for(int i = 0; i<nbL; i++){
            getline(BfileR, line);
            tab[i] = line;
        }
        livresOfB.insert({Bcode, tab});
        nbB++;
    }
    cout << nbB << " bibliothèques chargées" << endl;
    ifstream LfileR (Lfile_name);
    string Ltype, Lcode, Lname, Lauthor, Leditor, Lisbn, Lp, Lstate, Lbiblio, Lsupp;
    map<string,Livre*> mapL;
    int nbL = 0;
    while(getline(LfileR, Ltype)){
        getline(LfileR, Lcode);
        getline(LfileR, Lname);
        getline(LfileR, Lauthor);
        getline(LfileR, Leditor);
        getline(LfileR, Lisbn);
        getline(LfileR, Lp);
        getline(LfileR, Lstate);
        getline(LfileR, Lbiblio);
        getline(LfileR, Lsupp);
        Bibliotheque* biblio = mapB.lower_bound(Lbiblio)->second;
        int isbn = stoi(Lisbn);
        if(Ltype == "Bande Dessinée"){
            auto* bd = new BandeDessinee(Lcode, Lname, Lauthor, Leditor, isbn, Lp, Lstate, biblio, Lsupp);
            mapL.insert({Lcode, bd});
        }
        else if(Ltype == "Recueil de Poésie"){
            auto* rp = new RecueilPoesie(Lcode, Lname, Lauthor, Leditor, isbn, Lp, Lstate, biblio, Lsupp);
            mapL.insert({Lcode, rp});
        }
        else if(Ltype == "Roman"){
            auto* r = new Roman(Lcode, Lname, Lauthor, Leditor, isbn, Lp, Lstate, biblio, Lsupp);
            mapL.insert({Lcode, r});
        }
        else if(Ltype == "Album"){
            auto* a = new Album(Lcode, Lname, Lauthor, Leditor, isbn, Lp, Lstate, biblio, Lsupp);
            mapL.insert({Lcode, a});
        }
        else if(Ltype == "Pièce de théatre"){
            auto* pt = new PieceTheatre(Lcode, Lname, Lauthor, Leditor, isbn, Lp, Lstate, biblio, Lsupp);
            mapL.insert({Lcode, pt});
        }
        nbL++;
    }
    cout << nbL << " livres chargés" << endl;
    int biblio_ind = 0;
    for(auto bc: mapB){
        Bibliotheque* biblio = bc.second;
        string code = bc.first;
        int tBnbL = nbLOfB.lower_bound(code)->second;
        string* LcodesOfB = livresOfB.lower_bound(code)->second;
        for(int i = 0; i<tBnbL; i++){
            string lcode = LcodesOfB[i];
            Livre* livre = mapL.lower_bound(lcode)->second;
            biblio->ajoutLivre(livre);
        }
        BIBLIO[biblio_ind] = biblio;
        biblio_ind++;
    }
    *nbBiblio = nbB;
    cout << "Les livres ont rejoint leurs bibliothèques" << endl;
    ifstream AfileR (Afile_name);
    string AlastName, AfirstName, Aadress, Anum, Abiblio, AnbE, AnbL;
    map<string, Adherent*> mapA;
    map<string, string*> livresOfA;
    map<string, int> nbLOfA;
    int nbA = 0;
    while(getline(AfileR, AlastName)){
        getline(AfileR, AfirstName);
        getline(AfileR, Aadress);
        getline(AfileR, Anum);
        getline(AfileR, Abiblio);
        getline(AfileR, AnbE);
        getline(AfileR, AnbL);
        Bibliotheque* biblio = mapB.lower_bound(Abiblio)->second;
        auto* a = new Adherent(AlastName, AfirstName, Aadress, stoi(Anum), biblio, stoi(AnbE));
        mapA.insert({Anum, a});
        int A_nbL = stoi(AnbL);
        nbLOfA.insert({Anum, A_nbL});
        tab = new string[A_nbL];
        for(int i = 0; i<A_nbL; i++){
            getline(AfileR, line);
            tab[i] = line;
        }
        livresOfA.insert({Anum, tab});
        nbA++;
    }
    cout << nbA << " adhérents chargés" << endl;
    int adher_ind = 0;
    for(auto ac: mapA){
        Adherent* a = ac.second;
        string code = ac.first;
        int tAnbL = nbLOfA.lower_bound(code)->second;
        string* LcodesOfA = livresOfA.lower_bound(code)->second;
        for(int i = 0; i<tAnbL; i++){
            string lcode = LcodesOfA[i];
            Livre* livre = mapL.lower_bound(lcode)->second;
            livre->setEtat("Libre");
            a->emprunter(lcode);
        }
        ADHER[adher_ind] = a;
        adher_ind++;
    }
    *nbAdher = nbA;
    cout << "Les livres ont rejoint les adhérents" << endl;
    cout << "Toutes les données sont chargées" << endl;
}

void save(Bibliotheque** BIBLIO, const int* nbBiblio, Adherent** ADHER, const int* nbAdher){
    cout << "Enregistrement dans les fichiers : " << Afile_name << ' ' << Bfile_name << ' ' << Lfile_name << endl;
    ofstream AfileW (Afile_name);
    for(int i = 0; i<*nbAdher; i++){
        Adherent* adher1 = ADHER[i];
        AfileW << adher1->getNom() << endl;
        AfileW << adher1->getPrenom() << endl;
        AfileW << adher1->getAdresse() << endl;
        AfileW << adher1->getNumero() << endl;
        AfileW << adher1->getBibliotheque()->getCode() << endl;
        AfileW << adher1->getNbEmprunts() << endl;
        Livre** tab = adher1->getEmprunts();
        int tablength = adher1->getEmpruntsLength();
        AfileW << tablength << endl;
        for(int j = 0; j<tablength; j++){
            AfileW << tab[j]->getCode() << endl;
        }
    }
    cout << *nbAdher << " adhérents enregistrés" << endl;
    int nbLivres = 0;
    ofstream BfileW (Bfile_name);
    ofstream LfileW (Lfile_name);
    for(int i = 0; i<*nbBiblio; i++){
        Bibliotheque* biblio1 = BIBLIO[i];
        BfileW << biblio1->getNom() << endl;
        BfileW << biblio1->getAdresse() << endl;
        BfileW << biblio1->getCode() << endl;
        Livre** tab = biblio1->getLivres();
        int tabLength = biblio1->getNbLivre();
        nbLivres += tabLength;
        BfileW << tabLength << endl;
        for(int j = 0; j<tabLength; j++){
            Livre* livre1 = tab[j];
            BfileW << tab[j]->getCode() << endl;
            LfileW << livre1->getCategorie() << endl;
            LfileW << livre1->getCode() << endl;
            LfileW << livre1->getTitre() << endl;
            LfileW << livre1->getAuteur() << endl;
            LfileW << livre1->getEditeur() << endl;
            LfileW << livre1->getISBN() << endl;
            LfileW << livre1->getPublicConcerne() << endl;
            LfileW << livre1->getEtat() << endl;
            LfileW << livre1->getProprietaire()->getCode() << endl;
            LfileW << livre1->getAttributSpe() << endl;
        }
    }
    cout << *nbBiblio << " bibliothèques enregistrées" << endl;
    cout << nbLivres << " livres enregistrés" << endl;
    cout << "Toutes les données sont enregistrées" << endl;
}
