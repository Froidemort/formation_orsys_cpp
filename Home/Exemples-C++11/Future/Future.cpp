// Debut de ./Home/Exemples-C++11/Future/Future.cpp
// inspire de 'http://www.cplusplus.com'
// ------------------------------------------------------------------- 73
// A compiler avec -std=c++14

#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // 1s

// a non-optimized way of checking for prime numbers:
bool is_prime( int x) {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for( 1s) ;
    for (int i=2; i<x; ++i) if (x%i==0) return false;
    return true;
}


int main() {  // ----------------------------------------------------- 73

    std::cout << "Checking whether 313222313 is prime.\n";
    std::future< bool> fut = std::async( is_prime, 313222313);

    std::cout << "Calculating. Please, wait\n";
    // get() est bloquante (sinon) attend que l'etat du future soit connu
    bool ret = fut.get();

    if ( ret ) std::cout << "It is prime!\n";
    else std::cout << "It is not prime.\n";

    return 0;
}   // fin de fichier
