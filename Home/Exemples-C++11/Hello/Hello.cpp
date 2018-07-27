// Debut de ./Home/Exemples-C++11/Hello/Hello.cpp
#include <iostream>      // std::cerr std::endl
#include <thread>        // std::thread std::this_thread std::chrono
#include <chrono>        // std::chrono (inclus aussi depuis ci dessus)

const std::chrono::seconds DeuxSecondes( 2) ;
void fThread( void) ;

int main( void) { // ------------------------------------------------- 73
    std::thread MonThread( fThread) ;    // Creation-Lancement du thread
//  std::this_thread::sleep_for( DeuxSecondes) ;            // AAAA
    std::cerr << "Goodbye!" << std::endl;
//  MonThread.join();                                       // CCCC
}

void fThread( void) {  // -------------------------------------------- 73
    std::cerr << "Hello world..." << std::endl;
//  std::this_thread::sleep_for( DeuxSecondes) ;            // BBBB
}
// fin de ./Home/Exemples-C++11/Hello/Hello.cpp
