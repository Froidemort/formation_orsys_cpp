// Fichier './Exemples/Polygone/Rectangle.cpp'

#include "Rectangle.h"

Rectangle::Rectangle( std::istream &s): Polygone( 4) {

    int tmp ;
    std::cerr << "Rectangle : entrez largeur et hauteur\n" ;

    std::cerr << "\tlargeur " << ": " ; s >> tmp ;
    SetCote( 0, tmp) ; SetCote( 2, tmp) ;

    std::cerr << "\thauteur " << ": " ; s >> tmp ;
    SetCote( 1, tmp) ; SetCote( 3, tmp) ;
}

// Fin de './Exemples/Polygone/Rectangle.cpp'
