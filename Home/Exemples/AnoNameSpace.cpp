// Fichier './Exemples/AnoNameSpace.cpp'

#include <iostream>

namespace {
    int x1 = 11;
    namespace {
        int y1 = 111;
} }

namespace {
    int x2 = 22;
    namespace {
        int y2 = 222;
} }

int x3 = 33 ;

int main( void) {
    

    std::cout << "x1 = " << x1 << std::endl ;
    std::cout << "x2 = " << x2 << std::endl ;
    std::cout << "x3 = " << x3 << std::endl ;
    std::cout << "y1 = " << ::x1 << std::endl ;
    std::cout << "y1 = " << y1 << std::endl ;
//    std::cout << "y1 = " << ::y1 << std::endl ;     // Ne compile plus
//    std::cout << "y1 = " << ::::y1 << std::endl ;   // Ne compile pas

// Il y a un warning du fait que y2 n'est pas utilise:
// line 14: warning: '{anonymous}::{anonymous}::y2' defined but not used

    return 0 ;
}                  // Fin de './Exemples/AnoNameSpace.cpp'
