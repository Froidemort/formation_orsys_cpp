// Fichier './Exemples/References.cpp'

#include <iostream>

void Affiche( const int &z) {
    std::cout << "z et &z: " << z << " et " << &z << std::endl ;
}

int main( void) {

    int x = 88 ;
    int &y = x ; y++ ;  // x et y designent la meme variable,
                        // Pour le compilateur x et y designent
                        // le meme emplacement en memoire, 

    // autrement dit les adresses '&x' et '&y' sont identiques:

    std::cout << "x et &x: " << x << " et " << &x << std::endl ;
    std::cout << "y et &y: " << y << " et " << &y << std::endl ;
    Affiche( x) ;

    return 0 ;
}   // Fin de './Exemples/References.cpp'
