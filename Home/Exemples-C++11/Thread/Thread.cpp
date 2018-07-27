// Debut de ./Exemples-C++11/Thread/Thread.cpp
#include <thread>        //  std::thread
#include <iostream>      //  std::cout

int foo( char c ) {      // Le type retour n'a pas d'importance
    int i=0 ;
    while ( i++ < 500 ) std::cout << c ;
    return 0;
}

int main( void) {
                  // A ne surtout pas utiliser ! (mais on est curieux)
    std::cout << "sizeof (std::thread) " << sizeof (std::thread) << '\n';
    std::cout << "sizeof (long) "  << sizeof (long)  << '\n' ;
    std::cout << "sizeof (char*) " << sizeof (char*) << '\n' ;

    std::thread T1( foo, 'A'+0) ;
    std::thread T2( foo, 'A'+1) ;
    std::thread T3( foo, 'A'+2) ;
    T1.join() ; T2.join() ; T3.join() ; 

    std::cout << "\nfin du programme\n" ; return 0;
}   // fin de fichier
