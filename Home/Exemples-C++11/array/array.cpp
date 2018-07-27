// debut de ./Exemples-C++11/array/array.cpp
#include <iostream>                  // std::cout
#include <array>                     // std::array std::size() ...
int main () { // ---------------------------------------------------70

    std::array< int, 5> Entiers ;    // Seul constructeur: ctor vide 
    std::cout << "\nTaille du tableau : " << Entiers.size()   << '\n';
    std::cout << "sizeof (Entiers)  : " << sizeof (Entiers) << '\n' ;
    std::cout << "ou encore         : " 
              << sizeof Entiers.front() * Entiers.size() << '\n' ;
    Entiers[ 0] = 666 ;
    Entiers[ 5] = 777 ;              // Pas de test de debordement
    try {
        Entiers.at( 5) = 555 ;       // operator[] avec verifications
    } catch ( std::exception& e ) {
        std::cout << "erreur debordement: " << e.what() << "\n\n" ;
    }
    size_t i=0 ; for ( auto elem : Entiers ) {
        std::cout << "element " << i++ << " : " << elem << "\n" ;
    }
}   // fin de fichier
