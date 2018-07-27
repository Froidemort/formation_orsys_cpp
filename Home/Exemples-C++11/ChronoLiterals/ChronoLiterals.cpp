// Debut de ./Exemples-C++11/ChronoLiterals/ChronoLiterals.cpp
#include <iostream>
#include <chrono>
 
int main() {  // ----------------------------------------------------- 73

    using namespace std::chrono_literals;

    auto TrenteSecondes = 30s  ;
    std::cout << "30s  = " << TrenteSecondes.count() << " secondes\n" ;

    auto CinqMinutes    = 5min ;
    std::cout << "5min = " << CinqMinutes.count() << " minutes\n" ;

    std::cout << "5min = " << (CinqMinutes+0s).count() << " secondes\n" ;
    std::cout << "24h = "  << (24h).count() << " heures\n" ;
    std::cout << "24h = "  << (24h+0min).count() << " minutes\n" ;
    std::cout << "24h = "  << (24h+0s).count() << " secondes\n" ;
}   // fin de fichier
