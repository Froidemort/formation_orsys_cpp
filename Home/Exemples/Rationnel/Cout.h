// Debut de './Exemples/Rationnel/Cout.h'
#include <iostream>

inline std::ostream &operator << (
       std::ostream &c,
       const Rationnel &r
) {
    return c << r.num << '/' << r.den ;
}

// Fin de './Exemples/Rationnel/Cout.h'
