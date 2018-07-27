// Fichier ./Home/Thread/Thread.cpp

#include <thread>   // std::thread
#include <iostream> // std::cerr

void f( void) {
    int i=0 ;
    while ( i++ < 500 ) std::cerr << '-' ;
    std::cerr << "i==" << i << " dans f()\n" ;
}

int main( void) {
    int i=0;
    std::thread t( f) ;

    while ( i++ < 500 )  std::cerr << 'o' ;
    std::cerr << "i==" << i << " dans main()\n" ;
    return 0;
}   // Fin de ./Home/Thread/Thread.cpp
