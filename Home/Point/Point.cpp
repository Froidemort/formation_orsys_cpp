// Fichier './Point/Point.cpp'
// Fichier './Corriges/Point/Point.cpp'

#include <iostream>
#include "Point.h"

using namespace std ;

void Point::Affiche(
    const char * const mess
) const {
    cout << "point en x=" << _x <<  ", y=" << _y ;
    if ( mess) cout << "   (initialement avec " << mess << ")" ;
    cout << endl ;
}



// Fin de './Point/Point.cpp'
