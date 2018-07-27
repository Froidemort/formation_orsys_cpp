// Fichier './Corriges/Cercle/Cercle.cpp'
// Fichier './Cercle/Cercle.cpp' (lien physique)

#include <iostream>
#include "Cercle.h"

#if defined( __linux__)
    #include <math.h>   // pour M_PI puis pi
    const double Pi = (double)(M_PI) ;
#else
    const double Pi = acos( -1) ;
#endif



Cercle::Cercle( //----------------------------
    int x, int y, int r
) : Point( x, y), rayon( r) {}


Cercle::Cercle( //----------------------------
    const Point &pt, int r
) : Point( pt), rayon( r) {}


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

// Fin de './Cercle/Cercle.cpp'
