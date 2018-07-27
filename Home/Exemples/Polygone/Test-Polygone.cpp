// Fichier './Exemples/Polygone/Test-Polygone.cpp'

#include <iostream>
#include "Polygone.h"
using namespace std ;

int main( void) {

    Polygone B(3), A ;
    B.SetCote( 0, 5) ;
    B.SetCote( 1, 7) ;
    B.SetCote( 2, 3) ;

    A.Affiche() ; B.Affiche() ;

    { Polygone C( B) ; C.Affiche() ; }

    { Polygone D = B ;   // Appel du constructeur de copie comme ci dessus
      D.Affiche() ;
      A = D ;            // Affectation cette fois
    }
    A.Affiche() ;

    return 0 ;
}

// Fin de './Exemples/Polygone/Test-Polygone.cpp'
