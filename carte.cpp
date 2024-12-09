/* INF3105 - Structures de données et algorithmes - Automne 2023
   Source de départ du TP5 par Éric Beaudry.
   
   Vos noms et codes parmaments:
    1) Prénom Nom (NOMP01234567) 
*/
#include <limits>
#include "carte.h"
using namespace std;

void Carte::ajouter_noeud(long osmid, const PointSTerre& p){
    // À coder.
}

void Carte::ajouter_route(const string& nom, const list<long>& noeuds){
    // À coder.
}

void Carte::ajouter_cafe(const string& nom, const PointSTerre& p){
    // À coder.
}

double Carte::calculer_chemin(const PointSTerre& a, const PointSTerre& b, list<PointSTerre>& chemin) const{
    // À coder.
    // En principe, l'algorithme de Dijkstra.
    return numeric_limits<double>::infinity();
}

string Carte::suggerer_lieu_rencontre(const PointSTerre& membre1, const PointSTerre& membre2, double& d1, double& d2, list<PointSTerre>& chemin1, list<PointSTerre>& chemin2) const{
    // À coder.
    d1 = d2 = numeric_limits<double>::infinity();
    chemin1.clear();
    chemin2.clear();
    return "Impossible!";
}

