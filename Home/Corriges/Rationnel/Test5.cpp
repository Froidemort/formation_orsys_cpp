// Fichier './Corriges/Rationnel/Test5.cpp'

#include "Rationnel.h"
using namespace std ;

int main( void) {

    Rationnel A( 3, 4) ;
    
    cout << "A " << A << " avant" << endl ;
    A -= 1 ;
    cout << "A " << A << " apres" << endl ;

    A -= Rationnel( -1, 4) ;
    cout << "A -= Rationnel(-1,4) " << A << " vaut 0!" << endl ;

    return 0;
}

// Fin de './Corriges/Rationnel/Test5.cpp'
