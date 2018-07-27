// Debut de ./Exemples-C++11/2Mutex/2Mutex.cpp
#include <thread>   //  std::thread
#include <mutex>    //  std::mutex
#include <iostream> //  std::cout

const size_t nTh = 2 ;           // Nombre de threads a demarrer
std::mutex Mutex[ nTh] ;

void foo( size_t i) {
    for (;;) {
        int n=0 ;
        Mutex[ i].lock() ;
        while (n++<50) { std::cout<<(char)('A'+i); } std::cout<<'\n';
        Mutex[ (i+1)%nTh].unlock() ;
    }
}

int main( void) { // ---------------------------------------------- 70

    for ( size_t i=0; i<nTh; i++) Mutex[ i].lock() ;
    std::thread T[ nTh] ;
    for ( size_t i=0; i<nTh; i++) T[ i] = std::thread( foo, i) ;

    Mutex[ 0].unlock() ;  // Commence par 'A', puis alterne avec 'B'

    using namespace std::chrono_literals; // '1s' ci dessous en C++14
    std::this_thread::sleep_for( 1s) ;    // Arret un peu violent
    std::cerr << "\nfin du programme\n" ; return 0;
}   // fin de fichier
