// Debut de ./Exemples-C++11/Mutex/Mutex.cpp
#include <thread>   //  std::thread
#include <mutex>    //  std::mutex
#include <iostream> //  std::cout

std::mutex Mutex ;

void foo( char c ) {            // Le type retour n'a pas d'importance
    for (;;) {
        int i=0 ;
        Mutex.lock() ;
        while ( i++ < 50 ) { std::cout << c ; } std::cout << '\n' ;
        Mutex.unlock() ;
    }
}

int main( void) { // ---------------------------------------------- 70

    Mutex.lock() ;          // les threads vont reellement demarrer...
    std::thread T1( foo, 'A'+0) ;
    std::thread T2( foo, 'A'+1) ;
    Mutex.unlock() ;                      // ... ici !

    using namespace std::chrono_literals; // '1s' ci dessous en C++14
    std::this_thread::sleep_for( 1s) ;    // Arret un peu violent
    std::cerr << "\nfin du programme\n" ; return 0;
}   // fin de fichier
