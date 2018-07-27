// Fichier './Triangle/Triangle.cpp'

#include <iostream>
#include "Triangle.h"



Triangle::Triangle( int s1, int s2, int s3) : Polygone( 3) {

    if ( TriangleOK( s1, s2, s3) ) {

        Polygone::SetCote( 0, s1) ;   // Test-5: on utilise SetCote() de la classe
        Polygone::SetCote( 1, s2) ;   // de base: elle ne verifie pas les cotes :o)
        Polygone::SetCote( 2, s3) ;

    } else {    // Pourtant c'est un polygone licite :o(
        std::cerr << s1 << ", " << s2 << ", " << s3;
        std::cerr << " ne font pas un triangle\n" ;
    }
}





Triangle::Triangle( const Polygone &P) : Polygone( 3) {    // Test-3

    if ( P.GetNbCotes() != 3 ) {
        std::cerr << "Impossible de creer un triangle depuis un polygone quelconque\n" ;
        return ;
    }

    int s1 = P.GetCote( 0) ;
    int s2 = P.GetCote( 1) ;
    int s3 = P.GetCote( 2) ;

    if ( TriangleOK( s1, s2, s3 ) ) {

        Polygone::SetCote( 0, s1) ;   // Test-5: on utilise SetCote() de la classe
        Polygone::SetCote( 1, s2) ;   // de base: elle ne verifie pas les cotes :o)
        Polygone::SetCote( 2, s3) ;

    } else {
        std::cerr << "Impossible de creer un triangle depuis ce polygone a 3 cotes\n" ;
        std::cerr << s1 << ", " << s2 << ", " << s3;
        std::cerr << " ne font pas un triangle\n" ;
    }
}





Triangle &Triangle::operator = ( const Polygone &P) {
 
    std::cerr << "(debug) affectation d'un polygone a un triangle" << std::endl ;

    if ( P.GetNbCotes() != 3 ) {
        std::cerr << "Impossible de copier un polygone quelconque dans un triangle\n" ;
        return *this ;
    }

    int s1 = P.GetCote( 0) ;
    int s2 = P.GetCote( 1) ;
    int s3 = P.GetCote( 2) ;

    if ( TriangleOK( s1, s2, s3 ) ) {

        Polygone::SetCote( 0, s1) ;   // Test-5: on utilise SetCote() de la classe
        Polygone::SetCote( 1, s2) ;   // de base: elle ne verifie pas les cotes :o)
        Polygone::SetCote( 2, s3) ;

    } else {
        std::cerr << "Impossible de copier ce polygone a 3 cotes dans un triangle\n" ;
        std::cerr << s1 << ", " << s2 << ", " << s3;
        std::cerr << " ne font pas un triangle\n" ;
    }
    return *this ;
}





Triangle::Triangle( int s) : Polygone( 3) {     // Test-2
    Polygone::SetCote( 0, s) ; Polygone::SetCote( 1, s) ; Polygone::SetCote( 2, s) ;
}





Triangle::Triangle( std::istream &s) : Polygone( 3) {

    int tmp ;
    std::cerr << "Triangle : entrez la longueur des cotes\n" ;
    for ( int i=0; i<3; i++) {
        std::cerr << "\tcote " << i+1 << ": " ;
        s >> tmp ;
        Polygone::SetCote( i, tmp) ;
    }

    if ( ! TriangleOK( TabLongueurs[ 0], TabLongueurs[ 1], TabLongueurs[ 2]) ) {

        std::cerr << TabLongueurs[ 0] << ", " << TabLongueurs[ 1] << ", " ;
        std::cerr << TabLongueurs[ 2] << " ne font pas un triangle\n" ;
        Polygone::SetCote( 0, 0) ; Polygone::SetCote( 1, 0) ; Polygone::SetCote( 2, 0) ;
     }
}





void Triangle::Affiche( void ) const {
    std::cout << "Triangle:\t" ;
    for ( int i=0; i<GetNbCotes(); i++)
        std::cout << " " << TabLongueurs[ i] ;
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
