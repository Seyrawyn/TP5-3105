/* INF3105 - Structures de données et algorithmes - Automne 2023
   Source de départ du TP5 par Éric Beaudry.
   Classe PointSTerre : Point sur la surface de la Terre en coordonnées (latitude,longitude).
   Vous ne devriez pas avoir à modifier ce fichier.
*/
#if !defined(__POINT_H__)
#define __POINT_H__
#include <iostream>

// Cette classe représente un point sur la surface de la Terre.
class PointSTerre {
  public:
    double distance(const PointSTerre&) const;
  private:
    double latitude;  // angle en radians
    double longitude; // angle en radians

  friend std::ostream& operator << (std::ostream&, const PointSTerre&);
  friend std::istream& operator >> (std::istream&, PointSTerre&);
};

#endif

