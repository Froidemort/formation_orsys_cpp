// Debut de ./Corriges-C++11/RegExp/RegExp.cpp
#include <iostream>   // sd::cin std::cout getline()
#include <regex>      // std::regex std::regex_search std::regex_match
#include <string>     // std::string

int main() {  // -------------------------------------------------- 70

    std::string Ligne ;
//  std::regex  Entier( "(\\+|-)?[[:digit:]]+") ; // ECMAScript
    std::regex  Entier( "[+-]?[0-9]+");// Grammaire conforme a 'egrep'

    std::cout << "Saurez-vous saisir un entier par ligne...\n" ;
    for ( ;; ) {

        std::cout << "> " ;
        getline( std::cin, Ligne);
        if ( std::regex_search( Ligne, std::regex( "^ *(q|Q)")) ) {
            return 0 ;
        } else if ( regex_match( Ligne, Entier) ) {
            std::cout << "entier detecte >" << Ligne << "<\n" ;
            std::cout << "gagne...\n" ;
        } else {
            std::cout << ">" << Ligne << "< n'est pas un entier\n" ;
            std::cout << "Vous avez craque ou perdu...\n" ;
            return 1 ;
        }
    }
    return 2 ;
}   // fin de fichier
