// Fichier './Home/Corriges/Auto/Auto-2.cpp'
#include <iostream>                 // std::cout std::endl
#include <vector>                   // std::vector

int main( void) {

    std::vector< int> v{ 1, 3, 5, 7 };

    for (
		  auto it = v.cbegin() ;   // cbegin() au lieu de begin() 
          it != v.end() ;          // v.cend() serait coherent, mais
          it++                     // v.end() est suffisant
    ) {

//        *it = 0 ;
        std::cout << *it << " " ;
    }
    std::cout << std::endl ;
    return 0 ;
}    // fin de fichier
