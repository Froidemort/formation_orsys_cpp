// Fichier './Exemples/Cercle/Cercle.cpp'

#include <iostream>
#include "Cercle.h"


#include <math.h>   // pour M_PI puis pi
const double Pi = (double)(M_PI) ;

Cercle::Cercle( //----------------------------
    int x, int y, int r
) : Point( x, y), rayon( r) {}


Cercle::Cercle( //----------------------------
    const Point &pt, int r
) : Point( pt), rayon( r) {}


Cercle::Cercle( //----------------------------
    const Cercle &c
) : Point( c), rayon( c.rayon) {}


double Cercle::Aire( //-----------------------
    void
) const {
   return Pi * rayon * rayon ;
}


double Cercle::Perimetre( //------------------
    void
) const {
   return 2 * Pi * rayon ;
}

// Fin de './Exemples/Cercle/Cercle.cpp'
