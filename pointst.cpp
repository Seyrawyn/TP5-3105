/*  INF3105 | Structures de données et algorithmes
    UQAM | Département d'informatique
    http://ericbeaudry.uqam.ca/INF3105/
    Fichier pointst.cpp © Éric Beaudry.
*/
#include <cassert>
#include <cmath>
#include "pointst.h"

const double PI=3.14159265359;
const double RAYON_TERRE=6371 * 1000;  // en mètres

double PointSTerre::distance(const PointSTerre& point) const {
    double s1 = sin((point.latitude-latitude)/2);
    double s2 = sin((point.longitude-longitude)/2);
    return 2*RAYON_TERRE * asin(sqrt(s1*s1 + cos(latitude)*cos(point.latitude)*s2*s2));
}

std::ostream& operator << (std::ostream& os, const PointSTerre& point) {
    // Écrit en degrés.
    os << "(" 
       << (point.latitude * 180.0 / PI)
       << "," 
       << (point.longitude * 180.0 / PI)
       << ")";
    return os;
}

std::istream& operator >> (std::istream& is, PointSTerre& point) {
    // Lit en degrés.
    char po, vir, pf;
    is >> po;
    if(is){
        is >> point.latitude >> vir >> point.longitude >> pf;
        assert(po=='(');
        assert(vir==',');
        assert(pf==')');
        point.latitude  *= PI / 180.0;
        point.longitude *= PI / 180.0;
    }
    return is;
}

