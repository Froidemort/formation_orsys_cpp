// Debut de ./Exemples-C++11/ConvDuration/ConvDuration.cpp
#include <chrono>        // std::chrono ...
#include <iostream>      // std::cout
#include <iomanip>       // std::setfill() std::setw()


int main() { // ------------------------------------------------------ 73
    using namespace std::chrono;

    milliseconds ms( 96776514l);
//  seconds       s(  32176); ms = s ; // Pour test de conversion

    hours   hh = duration_cast<   hours>(      ms);
    minutes mm = duration_cast< minutes>(      ms % hours( 1));
    seconds ss = duration_cast< seconds>(      ms % minutes( 1));
    milliseconds millis
               = duration_cast< milliseconds>( ms % seconds( 1));

    std::cout << std::setfill( '0') ;
    std::cout << std::setw( 2) << hh.count() << ':' ;
    std::cout << mm.count() << ':' ;
    std::cout << ss.count() << '.' ;
    std::cout << std::setw( 3) << millis.count() << '\n' ;

    return 0;
}   // fin de fichier
