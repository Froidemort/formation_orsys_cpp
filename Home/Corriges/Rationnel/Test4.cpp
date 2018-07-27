// Fichier './Corriges/Rationnel/Test4.cpp'

#include "Rationnel.h"
using namespace std ;

int main( void) {

    Rationnel A( 3, 4), D, E( 0, 6);

    cout << "+A " << +A << endl ;
    cout << "-A " << -A << endl ;
    cout << "D=-A " << (D=-A) << endl ;
    cout << "A " << A << " qui n'a pas change" << endl ;

    cout << "~A " << ~A << endl ;
    cout << "E " << ~E << endl ;
    return 0;
}

// Fin de './Corriges/Rationnel/Test4.cpp'
