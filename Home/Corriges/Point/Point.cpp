// Fichier './Corriges/Point/Point.cpp'
#include <iostream>
#include "Point.h"

using namespace std ;

void Point::Affiche(
    const char * const mess
) const {
    cout << "point( " << Id << ") en x=" << x <<  ", y=" << y ;
    if ( mess) cout << "   (initialise avec " << mess << ")" ;
    cout << endl ;
}

// Fin de './Corriges/Point/Point.cpp'
