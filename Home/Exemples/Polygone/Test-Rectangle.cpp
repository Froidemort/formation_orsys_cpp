// Fichier './Exemples/Polygone/Test-Rectangle.cpp'

#include "Rectangle.h"
using namespace std ;

int main( void) {

    Rectangle A ;
    Rectangle B( 5, 6) ;

    A.Affiche() ; B.Affiche() ;
    cout << "Aire de A: " << A.Aire() << endl ;
    cout << "Aire de B: " << B.Aire() << endl ;
    cout << "Aire de *((Polygone *)&B): " << ((Polygone *)&B)->Aire() << endl ;

    Rectangle C( std::cin) ;

    Polygone *p = &B ; p->Affiche() ;
    cout << "Aire de *p: " << p->Aire() << endl ;

    cout << "Fin normale du programme" << endl ;
    return 0 ;
}

// Fin de './Exemples/Polygone/Test-Rectangle.cpp'
