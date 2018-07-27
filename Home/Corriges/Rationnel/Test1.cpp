// Fichier './Corriges/Rationnel/Test1.cpp'

#include "Rationnel.h"
using namespace std ;

int main( void) {

    Rationnel A( 3, 4) ;
    Rationnel B( 1, 5) ;

    cout << "affiche A: " << A << endl ;
    cout << "affiche B: " << B << endl ;

    A+=B ;
    cout << "affiche A apres addition de B: " << A << endl ;

    return 0;
}

// Fin de './Corriges/Rationnel/Test1.cpp'
