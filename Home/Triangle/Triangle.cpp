// Fichier './Triangle/Triangle.cpp'

#include <iostream>
#include "Triangle.h"


Triangle::Triangle( int s1, int s2, int s3) : Polygone( 3) {

    if ( TriangleOK( s1, s2, s3) ) {

        SetCote( 0, s1) ; SetCote( 1, s2) ; SetCote( 2, s3) ;

    } else {    // Pourtant c'est un polygone licite :o(
        std::cerr << s1 << ", " << s2 << ", " << s3;
        std::cerr << " ne font pas un triangle\n" ;
    }
}

Triangle::Triangle ( const Polygone &p) {
        if (p.GetNbCotes() == 3){
            SetNbCotes(3) ;
            TabLongueurs = new int [ NbCotes] ;
            std::cout << "On est dans conversion Polygone->Triangle\n";
            for ( int i=0; i<NbCotes; i++) {
                std::cout << "TabLongueurs[ " << i << " ] = " << TabLongueurs[i] << "\n";
                TabLongueurs[i] = p.GetCote(i) ;
                std::cout << "TabLongueurs[ " << i << " ] = " << TabLongueurs[i] << "\n";                
            }
        }
        else {
            std::cerr << "NUL, c'est pas un triangle !!\n" ;
            return;
        }
}

Triangle::Triangle( std::istream &s) : Polygone( 3) {

    int tmp ;
    std::cerr << "Triangle : entrez la longueur des cotes\n" ;
    for ( int i=0; i<3; i++) {
        std::cerr << "\tcote " << i+1 << ": " ;
        s >> tmp ;
        SetCote( i, tmp) ;
    }

    if ( ! TriangleOK(
               TabLongueurs[ 0], TabLongueurs[ 1], TabLongueurs[ 2]) ) {
        std::cerr << TabLongueurs[ 0] << ", " << TabLongueurs[ 1] << ", " ;
        std::cerr << TabLongueurs[ 2] << " ne font pas un triangle\n" ;
        SetCote( 0, 0) ; SetCote( 1, 0) ; SetCote( 2, 0) ;
     }
}

void Triangle::Affiche( void ) const {
    std::cout << "Triangle:\t" ;
    for ( int i=0; i<GetNbCotes(); i++)
        std::cout << "affiche TabLongueurs[ " << i << " ] = " << TabLongueurs[i] << "\n";   
    std::cout << std::endl ;
}

void Triangle::SetCote( int i, int val ) {   // Test-5

    int s1 = val ;
    int s2 = GetCote( (i+1)%3) ;
    int s3 = GetCote( (i+2)%3) ;

    if ( i < 0 || i > 2 ) {
        std::cerr << "Erreur fatale interne 67156208\n" ;
        std::cerr << "L'affectation echoue\n" ;
        return ;
    }

    if ( TriangleOK( s1, s2, s3 ) ) {
        
        Polygone::SetCote( i, val) ;
    
    } else {
        std::cerr << "Cote impossible pour un triangle\n" ;
//      std::cerr << "(debug) " << s1 << " " << s2 << " " << s3 << "\n" ;
        std::cerr << "L'affectation echoue\n" ;
    }
}

// Fin de './Triangle/Triangle.cpp'
