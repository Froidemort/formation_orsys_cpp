// Debut de Home/Exemples-C++11/std__transform/std__transform.cpp
#include <vector>
#include <iostream>
#include <algorithm>

// affiche tous les elements du vecteur -------------------------- 70
inline void Liste( std::vector< std::string> const& v) {
    std::for_each( v.cbegin(), v.cend(),
        [] (std::string const& s) { std::cout << s <<  " " ; }
    ) ;
    std::cout << std::endl ;
}   // fin de Liste()


// std::transform d'une seule chaine en majuscules ---------------- 70
inline std::string& Upper( std::string& sin) {
    std::transform( sin.begin(), sin.end(), sin.begin(),
        []( char c) { return std::toupper ( c) ; }
    ) ;
    return sin ;
}   // fin de Upper()


int main() { // --------------------------------------------------- 70

    std::string Noms[] { "Denis", "esther", "Valerie", "HECTOR" };
    std::vector< std::string> v( Noms, Noms+4) ;
    Liste( v) ;

    std::vector< std::string> u ;
    std::copy( v.cbegin(), v.cend(), std::back_inserter( u)) ;
    Liste( u) ;

    std::string Denis( v[ 0]) ;
    std::cout << Denis << " --> " ; Upper( Denis) ;
    std::cout << Denis << std::endl ;

    // std::transform de toutes les chaines du std:vector
    std::vector< std::string> w ;
    std::transform( v.begin(), v.end(), std::back_inserter( w),
                    []( std::string& nom) { return Upper( nom) ; }
                ) ;
    Liste( w) ;
}   // end of file
