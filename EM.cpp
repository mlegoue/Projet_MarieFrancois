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


void load(){
    cout << Afile_name << ' ' << Bfile_name << ' ' << Lfile_name << endl;

    ifstream BfileR (Bfile_name);
    string Bname, Badress, Bcode;
    map<string,Bibliotheque*> mapB;
    while(getline(BfileR, Bname)){
        cout << Bname << endl;
        getline(BfileR, Badress);
        getline(BfileR, Bcode);
        auto* b = new Bibliotheque(Bname, Badress, Bcode);
        mapB.insert({Bcode, b});
    }
    cout << "Bibiothèques chargées" << endl;
    for(auto i: mapB){
        cout << i.second->getNom() << endl;
    }
    ifstream LfileR (Lfile_name);
    string Ltype, Lcode, Lname, Lauthor, Leditor, Lisbn, Lp, Lstate, Lbiblio, Lsupp;
    map<string,BandeDessinee*> mapLBD;
    map<string,RecueilPoesie*> mapLRP;
    map<string,Roman*> mapLR;
    map<string,Album*> mapLA;
    map<string,PieceTheatre*> mapLPT;
    while(getline(LfileR, Ltype)){
        cout << Ltype << endl;
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
        if(Ltype == "BandeDessinee"){
            auto* bd = new BandeDessinee(Lcode, Lname, Lauthor, Leditor, isbn, Lp, Lstate, biblio, Lsupp);
        }
    }
    cout << "fin du load" << endl;
}
