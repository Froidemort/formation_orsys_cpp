// Debut de ./Home/Atomic/Atomic.cpp
#define NB      ((size_t)20)
#define ITER    ((unsigned int)1000000)         // 1 million d'iterations
#include <iostream>
#include <thread>



void f( void) {
    static unsigned int MaSequence( 0) ;
    while ( 1 ) {
        unsigned int OldSequence = MaSequence ;
        MaSequence++ ;

        if ( MaSequence <= OldSequence ) {
            std::cerr << "Erreur: " << MaSequence << " ne doit jamais " ;
            std::cerr << "etre inferieur a " << OldSequence << std::endl;
            std::exit( 99) ;
        } else if ( MaSequence == ITER ) {// 1 message a l'ecran a priori
            std::cerr << "Success: " << MaSequence << std::endl ;
        } else ;

        if ( MaSequence >= ITER ) { // tous les threads se terminent
            return ;
        }
    }
}   // fin de la fonction de thread



int main( void) {

    std::thread Threads[ NB] ;
    size_t i ;
    for ( i=0; i<NB; i++) { Threads[ i] = std::thread( f) ; } 

    for ( i=0; i<NB; i++) { Threads[ i].join() ; std::cerr << '.' ; }
    std::cerr << std::endl ;

    return 0 ;
}   // fin de main()
