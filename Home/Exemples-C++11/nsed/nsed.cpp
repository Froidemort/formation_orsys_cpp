// Debut de ./Exemples-C++11/nsed/nsed.cpp (ou new sed)
#include <iostream>   // std::cin std::cout std::cerr getline()
#include <regex>      // std::regex set::regex_replace
#include <string>     // std::string

int main( int argc, char** argv) { // -------------------------------- 73
    if ( argc != 3 ) {
        std::cerr << "usage: nsed regexp chaine\n" ; return 2 ;
    }
    std::cerr << "Tapez des lignes... jusqu'a <ctrl-D>\n" ;

    std::regex  Reg( *(argv+1) ) ;
    std::string Chaine( *(argv+2)) ;

    for ( ;; ) {
        std::string Entree, Resultat ;
        std::getline( std::cin, Entree) ;
        if ( ! std::cin ) return 0 ;
        Resultat = std::regex_replace( Entree, Reg, Chaine) ;
        std::cout << Resultat << '\n' ;
    }
}   // fin de fichier
