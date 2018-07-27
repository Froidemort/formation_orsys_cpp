// Fichier './Tour/Test-Tour.cpp'
// Lien physique './Corriges/Tour/Test-Tour.cpp'

#include "../include/Tour.h"


int main( void) {

    Tour T ;

    while ( T.score() ) {
        T.Affiche() ;
        (void)T.nouveau_lancer() ;
    }

    T.Affiche() ;
    return 0 ;
}

// Fin de './Tour/Test-Tour.cpp'
