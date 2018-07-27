// Fichier './Home/Exemples-C++11/constexpr/constexpr.cpp'
#include <iostream>    // std::cout std::endl

// La fonction ne peut pas utiliser de variables. Compiler avec -Wvla
constexpr size_t TailleTab( void) { return 5 ; }

// inline size_t TailleTab( void) { return 5 ; } // Genere un vla !
// #define TailleTab() 5                         // Encore plus efficace


int main( void) {      // -------------------------------------------- 73

    int Tab[ TailleTab()] ;

    for ( size_t i=0 ; i<TailleTab(); i++) { Tab[ i]=100+i; }

    for ( size_t i=0 ; i<TailleTab()-1; i++) {
        std::cout << Tab[ i] << " - " ;
    }
    std::cout << Tab[ TailleTab()-1] << std::endl ;
    return 0 ;
}   // fin de fichier
