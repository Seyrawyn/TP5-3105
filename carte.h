/* INF3105 - Structures de données et algorithmes - Automne 2023
   Source de départ du TP5 par Éric Beaudry.
   
   Vos noms et codes parmaments:
    1) Prénom Nom (NOMP01234567) 
*/
#if !defined(__CARTE_H__)
#define __CARTE_H__

#include <istream>
#include <list>
#include <string>
#include "pointst.h"

class Carte{
  public:
    void ajouter_noeud(long osmid, const PointSTerre& p);
    void ajouter_route(const std::string& nom, const std::list<long>& noeuds);
    void ajouter_cafe(const std::string& nom, const PointSTerre& p);

    double calculer_chemin(const PointSTerre& a, const PointSTerre& b, std::list<PointSTerre>& chemin) const;
    std::string suggerer_lieu_rencontre(const PointSTerre& membre1, const PointSTerre& membre2, 
                 double& d1, double& d2, std::list<PointSTerre>& chemin1, std::list<PointSTerre>& chemin2) const;

  private:
    // À compléter.

  friend std::istream& operator >> (std::istream& is, Carte& carte);
};

#endif
