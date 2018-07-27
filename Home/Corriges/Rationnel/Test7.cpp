// Fichier './Corriges/Rationnel/Test7.cpp'

#include "Rationnel.h"
using namespace std ;

int main( void) {

    Rationnel A( 2, 3) ;
    double x = 0.85 ;
    double y = 17.85 ;
    
    cout << "A " << A << endl ;
    cout << "(double)A " << (double)A << endl ;
    cout << "(Rationnel)x " << (Rationnel)x << endl ;
    cout << "(Rationnel)y " << (Rationnel)y << endl ;

    return 0;
}

// Fin de './Corriges/Rationnel/Test7.cpp'
