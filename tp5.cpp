/* INF3105 - Structures de données et algorithmes - Automne 2023
   Source de départ du TP5 par Éric Beaudry.
   
   Vos noms et codes parmaments:
    1) Prénom Nom (NOMP01234567) 
*/
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits>
#include "carte.h"
using namespace std;

int main(int argc, const char** argv){
    if(argc<3){
        cout << "./tp5 carte.txt cafes.txt" << endl;
        return 1;
    }
    Carte carte;
    {
        // Lecture de la carte
        ifstream iscarte(argv[1]);
        if(iscarte.fail()){
            cerr << "Erreur d'ouverture du fichier carte: '" << argv[1] << "' !" << endl;
            return 2;
        }
        iscarte >> carte;
        //cerr << "Carte chargée!" << endl;
    }
    {
        // Lecture des cafés
        ifstream iscafes(argv[2]);
        if(iscafes.fail()){
            cerr << "Erreur d'ouverture du fichier cafés: '" << argv[2] << "' !" << endl;
            return 3;
        }
        while(iscafes){
            string nom;
            PointSTerre point;
            char pointvirgule=0;
            iscafes >> nom;
            if(!iscafes || nom.empty()) break;
            iscafes >> point >> pointvirgule >> ws;
            assert(pointvirgule==';');
            carte.ajouter_cafe(nom, point);
        }
        //cerr << "Cafés chargées!" << endl;
    }
    
    // Gardez cette ligne pour avoir le bon nombre de chiffres de précision pour l'affichage des coordonnées
    std::cout << std::setprecision(8);

    // Boucle principale : lecture et traitement des requêtes depuis l'entrée standard
    while(cin){
        cin >> ws;
        if(cin.fail() || cin.eof())
            break; // détection de la fin de l'entrée (fin du fichier (EOF) si rediction avec <   -ou-   Ctrl+D si lecture depuis la console)

        // Lecture d'une requête : la position initiale de 2 membres 
        PointSTerre membre1, membre2;
        char pointvirgule=0;
        cin >> membre1 >> membre2 >> pointvirgule;
        assert(pointvirgule==';');
        
        // Appel au calcul de la suggestion
        list<PointSTerre> chemin1, chemin2;
        double d1=0, d2=0;
        string cafe_suggeree = carte.suggerer_lieu_rencontre(membre1, membre2, d1, d2, chemin1, chemin2);
        
        // Affichage du résultat
        cout << cafe_suggeree << endl;
        if(d1 < numeric_limits<double>::infinity() && d2 < numeric_limits<double>::infinity())
            cout << (int) round(d1) << "m\t" << (int) round(d2) << "m" << endl;
        else
            cout << endl;
        for(list<PointSTerre>::iterator iter = chemin1.begin();iter!=chemin1.end();++iter)
            cout << *iter << '\t';
        cout << endl;
        for(list<PointSTerre>::iterator iter = chemin2.begin();iter!=chemin2.end();++iter)
            cout << *iter << '\t';
        cout << endl;
    }

    // Fin normale du programme !
    return 0;
}

