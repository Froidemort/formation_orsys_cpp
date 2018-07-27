// Debut de ./Home/Corriges-C++11/Atomic/Atomic.cpp

#define  NB     ((size_t)20)
#define  ITER   ((unsigned int)1000000)         // 1 million d'iterations

#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>



void f( void) {
    static std::atomic< unsigned int> MaSequence( 0) ;
    while ( 1 ) {
        unsigned int OldSequence = MaSequence ;
        MaSequence++ ;              // Operation atomique desormais
        if ( MaSequence <= OldSequence ) {
            // Le mutex est pour n'avoir qu'un seul message d'erreur
            static std::mutex Mutex ; Mutex.lock() ;
            std::cerr << "Erreur: " << MaSequence << " ne doit jamais " ;
            std::cerr << "etre inferieur a " << OldSequence << std::endl ;
            // Il est fait expres de ne jamais liberer le Mutex
            std::exit( 99) ;
        } else ;
        if ( MaSequence >= ITER ) { // Tous les threads se terminent
            return ;
        }
    }
}    // fin de la fonction de thread



int main( void) {

    std::thread Threads[ NB] ;
    size_t i ;
    for ( i=0; i<NB; i++) { Threads[ i] = std::thread( f) ; } 
    std::cerr << "Success: " << ITER << std::endl ;

    for ( i=0; i<NB; i++) { Threads[ i].join() ; std::cerr << '.' ; }
    std::cerr << std::endl ;

    return 0 ;
}    // fin de main()
