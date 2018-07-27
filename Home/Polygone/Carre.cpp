// Fichier './Exemples/Polygone/Carre.cpp'

#include "Carre.h"

Carre::Carre( std::istream &s): Rectangle() {
    int tmp ;
    std::cout << "Carre : entrez la longueur du cote\n" ;

    std::cout << "\tcote " << ": " ;
    s >> tmp ;
    for ( int i=0; i<4; i++)
        SetCote( i, tmp) ;
}

// Fin de './Exemples/Polygone/Carre.cpp'
