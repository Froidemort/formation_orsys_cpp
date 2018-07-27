// Fichier './Rand/Test-Rand.cpp'
// Lien physique './Corriges/Rand/Test-Rand.cpp'

#include <iostream>
#include "Rand.h"

int main( void) {

    int i ;

    for ( i=0; i<10; i++) {
        std::cout << Rand() << ' ' ;
    }
    std::cout << "   ---   " ;
    for ( i=0; i<5; i++) {
        std::cout << Rand(100) << ' ' ;
    }
    std::cout << std::endl ;

    return 0 ;
}

// Fin de './Rand/Test-Rand.cpp'
