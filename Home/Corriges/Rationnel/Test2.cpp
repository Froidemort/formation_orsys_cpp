// Fichier './Corriges/Rationnel/Test2.cpp'

#include "Rationnel.h"
using namespace std ;

int main( void) {

    Rationnel A( 3, 4), B( 65, 15) ;
    Rationnel const &r = A ;
    const Rationnel &s = A ;

//  r += 1 ;  // Ne compile pas: 'r' est constant
//  s = B ;   // strictement identique au precedent

    cout << "affiche A " << A << endl ;
    cout << "affiche B " << B << endl ;
    cout << "affiche r " << r << endl ;
    cout << "affiche s " << s << endl ;

    return 0;
}

// Fin de './Corriges/Rationnel/Test2.cpp'
