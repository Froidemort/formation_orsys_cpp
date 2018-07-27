// Fichier './Corriges/Rationnel/Test3.cpp'

#include "Rationnel.h"
using namespace std ;

int main( void) {

    Rationnel A( 3, 4), B( 65, 15), C( 13, 3);


    cout << "affiche A " << A << endl ;
    cout << "affiche B " << B << endl ;
    cout << "affiche C " << C << endl ;

    cout << "A==B ? " << (A==B ? "oui" : "non") << endl ;
    cout << "B==C ? " << (B==C ? "oui" : "non") << endl ;
    cout << "A!=B ? " << (A!=B ? "oui" : "non") << endl ;
    cout << "B!=C ? " << (B!=C ? "oui" : "non") << endl ;

    return 0;
}

// Fin de './Corriges/Rationnel/Test3.cpp'
