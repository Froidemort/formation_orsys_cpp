#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>     /* getpid() */

unsigned int Rand( const unsigned int val_max) {
    static bool init = false ;
    if ( ! init ) {
        srand( time( 0 ) % getpid()) ;
        init = true ;
    }
    int number = rand() % val_max + 1;
    return number ;
}
