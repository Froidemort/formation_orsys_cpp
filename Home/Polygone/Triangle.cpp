// Fichier './Exemples/Polygone/Triangle.cpp'

#include "Triangle.h"

Triangle::Triangle( int s1, int s2, int s3) : Polygone( 3) {

    if ( TriangleOK( s1, s2, s3) ) {

        SetCote( 0, s1) ; SetCote( 1, s2) ; SetCote( 2, s3) ;

    } else {    // Pourtant c'est un polygone licite :o(
        std::cerr << s1 << ", " << s2 << ", " << s3;
        std::cerr << " ne font pas un triangle\n" ;
        SetCote( 0, 0) ; SetCote( 1, 0) ; SetCote( 2, 0) ;
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
        std::cerr << TabLongueurs[ 0] << "," << TabLongueurs[ 1] << ",";
        std::cerr << TabLongueurs[ 2] << " ne font pas un triangle\n" ;
        SetCote( 0, 0) ; SetCote( 1, 0) ; SetCote( 2, 0) ;
     }
}

// Fin de './Exemples/Polygone/Triangle.cpp'
