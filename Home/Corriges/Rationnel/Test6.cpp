// Fichier './Corriges/Rationnel/Test6.cpp'

#include "Rationnel.h"
using namespace std ;

int main( void) {

    Rationnel A( 2, 3) ;

    // les instructions ci dessous demandent explicitement une technique de conversion
//    int i = A ; // erreur a la compilation en tant qu'initialisation
//    int i ; i=A ; // erreur a la compilation en tant qu'affectation
    // Puis cela marche ...

    int i = A ;
    
    cout << "A " << A << endl ;
    cout << "i " << i << endl ;
    cout << "1/3 " << (int)Rationnel(1,3) << endl ;
    cout << "4/5 " << (int)Rationnel(4,5) << endl ;

    return 0;
}

// Fin de './Corriges/Rationnel/Test6.cpp'
