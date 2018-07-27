// Debut de ./Corriges-C++11/Auto/Auto-3.cpp
#include <iostream>                    // std::cout std::endl
#include <vector>                      // std::vector

int main( void) { // ---------------------------------------------- 70

    std::vector< int> v{ 1, 3, 5, 7 };
   
    for ( // i est du type de chaque element du std::vector<>
     	  const auto i : v	// i est une copie de chaque element
    ) {
//      i = 0 ;
        std::cout << i << " " ;
    }
    std::cout << std::endl ;
    return 0 ;
}   // fin de fichier
