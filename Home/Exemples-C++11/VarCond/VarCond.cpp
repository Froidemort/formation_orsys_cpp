// Debut de ./Exemples-C++11/VarCond/VarCond.cpp

#include <thread>             // std::thread
#include <mutex>              // std::mutex
#include <condition_variable> // std::condition_variable
#include <iostream>           // std::cout

std::mutex                    Mutex ;
std::condition_variable       VarCond ;

void foo( char c ) { // ------------------------------------------- 70

    // Commence par poser un verrou qui disparaitra tout seul...
    // Passer en attente condition libere implicitement le verrou
    std::unique_lock< std::mutex> Verrou( Mutex);  // Obligatoire ici
    for (;;) {
        VarCond.notify_one() ;  // Relache la condition pour un thread
        VarCond.wait( Verrou) ; // Passe en attente, libere le verrou
        int i=0 ; // wait est bloquant, attend la CV, prend le verrou
        while ( i++ < 50 ) { std::cout << c ; } std::cout << '\n' ;
    }
}

int main( void) { // ---------------------------------------------- 70

    std::thread T1( foo, 'A'+0) ;
    std::thread T2( foo, 'A'+1) ;
    VarCond.notify_one() ;
    Mutex.unlock() ;                             // ... ici !

    using namespace std::chrono_literals; // '1s' ci dessous en C++14
    std::this_thread::sleep_for( 1s) ;    // Arret un peu violent
    std::cerr << "\nfin du programme\n" ; return 0;
}   // fin de fichier
