// Fichier de './Triangle/Triangle.h'
#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "Polygone.h"

class Triangle : public Polygone {

    public :
        Triangle( int, int, int) ;
        Triangle( int a): Triangle(a,a,a) {}  ;
        Triangle( Polygone const &);        
        Triangle( std::istream &) ;
        Triangle( void) : Polygone( 3) {}
        void SetCote( int, int ) ;    // Test-5
        void Affiche( void) const ;
		~Triangle() {}

    private:
        static bool TriangleOK( int a, int b, int c) {
             return (a+b)>c && (b+c)>a && (a+c)>b ;
        }
} ;

#endif             // Fin de './Triangle/Triangle.h'
