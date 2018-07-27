// Debut de ./Exemples-C++11/Heure/Heure.cpp
#include <iostream>
#include <chrono>
//#include <ctime>   // semble etre inclus depuis "chrono"

int main()  // ---------------------------------------------------- 70
{
    using namespace std::chrono;
    high_resolution_clock::time_point p=high_resolution_clock::now() ;

    milliseconds ms=duration_cast<milliseconds>(p.time_since_epoch());

    seconds s = duration_cast< seconds>( ms);
    std::time_t t = s.count();
    std::cout << "\n    ctime()    " << std::ctime( &t) ;

    std::cout << "    et " << ms.count() % 1000 << " millisecondes\n";

    std::cout << "par curiosite sizeof (time_point): " ;
    std::cout << sizeof p << " et sizeof (time_t): " ;
    std::cout << sizeof (time_t) << '\n' ;
    return 0 ;
}   // fin de fichier
