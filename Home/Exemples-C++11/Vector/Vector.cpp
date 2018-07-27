// Fichier './Home/Exemples-C++11/Vector/Vector.cpp'
#include <iostream>
#include <vector>

int main( void) {  // ------------------------------------------------ 73
    std::vector< int> MonVecteur { 11, 22, 33, 44, 55} ;
    for ( const auto v : MonVecteur ) {
        std::cout << v ;
        if ( v != MonVecteur.back() ) std::cout << " - " ;
    }
    std::cout << std::endl ;
}   // fin de fichier
