#include ./Exemples-C++11/ThreadExcept
#include <iostream>
#include <thread>

void func( void) {
    std::cout << "un thread a demarre\n" ;
    throw std::exception() ;
}

int main() {
    try {
//      throw std::exception() ;   // Pour verification
        std::thread t1( func);
        std::thread t2( func);
        t1.join(); t2.join();
    } catch ( std::exception const& e ) {
        std::cout << "Une exception est traitee: " ;
        std::cout << e.what() << std::endl;
    }
}   // fin de fichier
