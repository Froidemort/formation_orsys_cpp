// Fichier './Home/Corriges/Auto/Auto-5.cpp'
#include <iostream>                 // std::cout std::endl
#include <vector>                   // std::vector

int main( void) {

    std::vector< int> v{ 1, 3, 5, 7 };
   
    for ( // i est du type de chaque element du std::vector<>
     	  const auto& i : v	// i est une reference int&
    ) {
//      i = 0 ;
        std::cout << i << " " ;
    }
    std::cout << std::endl ;
    return 0 ;
}    // fin de fichier
