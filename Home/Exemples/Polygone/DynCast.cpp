// Fichier './Exemples/Polygone/DynCast.cpp'

#include <iostream>
#include "Carre.h"
#include "Triangle.h"
using namespace std ;

int main( void) {       // Un Triangle est toujours un Polygone
                        // Tout Polygone n'est pas un Triangle
    Polygone P( 3) ;    // P est aussi un Triangle(0,0,0)    
//  Triangle *t = &P ;  // Ne compile pas:               // -1-
//  Triangle *t = (Triangle *)&P ; // compile, mais...
//                      // Affiche() du triangle ou du polygone ?
                        // solution en Exercice

    Triangle *t = dynamic_cast<Triangle *>( &P) ;
//  t->Affiche() ;      // Erreur de segmentation        // -2-

    Triangle &T = dynamic_cast<Triangle &>( P) ;
    T.Affiche() ;       // Exception std::bad_cast       // -3-

    return 0 ;
}

// Fin de './Exemples/Polygone/DynCast.cpp'
