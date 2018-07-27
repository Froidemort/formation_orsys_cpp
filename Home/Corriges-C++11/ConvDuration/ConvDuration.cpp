// Debut de ./Exemples-C++11/Corriges/ConvDuration.cpp
#include <chrono>        // std::chrono ...
#include <iostream>      // std::cout
#include <iomanip>       // std::setfill() std::setw()
#include <sstream>       // std::stringstream

std::string ToString( // ------------------------------------------ 70
    std::chrono::milliseconds const& ms
) {
    using namespace std::chrono; // Declaration pour la seule fonction

    hours   hh = duration_cast<   hours>(      ms);
    minutes mm = duration_cast< minutes>(      ms % hours( 1));
    seconds ss = duration_cast< seconds>(      ms % minutes( 1));
    milliseconds millis
               = duration_cast< milliseconds>( ms % seconds( 1));

	std::stringstream sout ;
    sout << std::setfill( '0') ;
    sout << std::setw( 2) << hh.count() << ':' ;
    sout << mm.count() << ':' ;
    sout << ss.count() << '.' ;
    sout << std::setw( 3) << millis.count() ;

	return sout.str() ;
}	



int main() { // --------------------------------------------------- 70

    std::chrono::milliseconds ms( 96776514l);
    std::chrono::seconds       s(  32176);

	std::cout << "\ndepuis qqs millisecondes: " << ToString( ms) ;
	// Ci dessous la conversion implicite se fait bien
	std::cout << "\ndepuis qqs secondes     : " << ToString(  s) ;
	std::cout << '\n' ;

    return 0;
}   // fin de fichier
