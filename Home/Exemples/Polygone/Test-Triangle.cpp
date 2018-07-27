// Fichier './Exemples/Polygone/Test-Triangle.cpp'

//#include <iostream>
#include "Triangle.h"
//using namespace std ;

int main( void) {

    Triangle A( 3, 3, 3); A.Affiche();
    Triangle B( 10, 1, 1); B.Affiche(); // no good
    Triangle C( std::cin); C.Affiche();
//  Triangle D( 1); D.Affiche(); //--->(1) ne compile pas

    C = A ; C.Affiche();

    Polygone E( 3);
    E.SetCote( 0, 3); E.SetCote( 1, 4); E.SetCote( 2, 5);
//  C = E ; E.Affiche(); C.Affiche(); //--->(2) ne compile pas
    C = *((Triangle *)&E) ; E.Affiche(); C.Affiche();

    Polygone F ; F = A ; F.Affiche() ;

    Polygone *p = &E ; p->Affiche() ;
              p = &A ; p->Affiche() ;

    A.SetCote( 0, 1000) ; A.Affiche(); // (3) Triangle impossible 
    A.SetCote( 10, 10) ; A.Affiche(); //---> Erreur a l'execution
    return 0 ;
}

// Fin de './Exemples/Polygone/Test-Triangle.cpp'
