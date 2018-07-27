// Debut de './Exemples-C++11/time/time.cpp'
#include <ctime>        // std::time_t std::asctime()
#include <iostream>     // std::cout std::wcout
 
int main()  // ---------------------------------------------------- 70
{   const std::time_t result = std::time( nullptr) ;
    std::cout << result << " seconds since the Epoch\n";
    std::wcout << std::asctime( std::localtime( &result));

    // a. on startup, the global locale is the "C" locale
    perror( 0) ;                // prints "Success" , "C" langage

    // b. we change it
    std::cout << "looking at user-preferred locale setting: ";
    std::locale Loc( "") ;      // reffers to the session's setting
    std::cout << Loc.name().c_str() << '\n';
    std::locale::global( Loc);  // changes the global locale
    perror( 0) ;                // It should have worked!

    // c. we need some translation since asctime() don't use locale
    char s[ 80] ;
    strftime( s, 79, "%a %m %b %Y\n", std::localtime( &result)) ;
    s[ 79] = '\0' ;
    std::wcout << s ;
}   // fin de fichier
