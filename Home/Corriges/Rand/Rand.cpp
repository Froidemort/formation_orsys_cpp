// Fichier 'Corriges/Rand/Rand.cpp'

#include <time.h>    // time()
#include <unistd.h>  // getpid()
#include <stdlib.h>  // srand()
#include "Rand.h"

unsigned int Rand(
    const unsigned int val_max
) {
    // FAIRE: un parametre supplementaire pourrait
    //        entrainer la generation d'une meme suite
    //        aleatoire, ce qui permettrait de rejouer
    //        des parties enregistrees par exemple.

    static bool init_ok = false ;

    if ( ! init_ok ) {
        srand( time( 0L) % getpid()) ;
        init_ok = true ;
    }
    return 1 + (unsigned int)( ((float)val_max * rand())
                               / (RAND_MAX + 1.0)) ;

}   // fin de 'Corriges/Rand/Rand.cpp'
