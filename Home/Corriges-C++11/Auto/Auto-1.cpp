// Fichier './Home/Corriges/Auto/Auto-1.cpp'
#include <iostream>
#include <vector>

int main( void) {

    std::vector< int> v{ 1, 3, 5, 7 } ;

    const auto& cv = v ; // Cree une reference 'const' intermediaire
    for ( auto it = cv.begin(); it != cv.end(); it++ ) {

//        *it = 0 ;
        std::cout << *it << " " ;
    }
    std::cout << std::endl ;
    return 0 ;
}   // fin de fichier
