// Fichier './Exemples/Polygone/Triangle.h'

#include <iostream>
#include "Polygone.h"

class Triangle : public Polygone {
    private:
        bool TriangleOK( int a, int b, int c) const {
             return (a+b)>c && (b+c)>a && (a+c)>b ;
        }

    public :
        Triangle( int, int, int) ;
        Triangle( std::istream &) ;
        Triangle( void) : Polygone( 3) {}

        void Affiche( void) const {
            std::cout << "Triangle ---- " ;
            Polygone::Affiche() ;
        }
} ;

// Fin de './Exemples/Polygone/Triangle.h'
