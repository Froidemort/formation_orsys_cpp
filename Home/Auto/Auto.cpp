// Fichier './Home/Auto/Auto.cpp'
#include <iostream>                 // std::cout std::endl
#include <vector>                   // std::vector

int main( void) {   // ----------------------------------------------- 73

    // Initialisation uniforme du C++11: plus besoin de mettre '=' 
    std::vector< int> v{ 1, 2, 3, 4 };

    for (
          std::vector< int>::const_iterator it = v.begin() ;     // BBBB
          it != v.end() ;                                        // BBBB
          it++                                                   // BBBB
    ) {

    // Ci dessous ne doit pas compiler: on verifie la nature 'const'
//        *it = 0 ;												 // AAAA
        std::cout << *it << " " ;
    }
    std::cout << std::endl ;
    return 0 ;
}    // fin de fichier
