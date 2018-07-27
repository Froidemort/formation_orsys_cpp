// Fichier ./Home/Exemples-C++11/static_assert/static_assert.cpp
#include <iostream>     // std::cout std::endl
#include <type_traits>  // std::is_arithmetic<>

template< class T>  //  ------------------------------------------- 70
T Double( T a) {
    static_assert(
        std::is_arithmetic< T>::value,
        "Le type transmis a 'Double< T>' doit etre arithmetique"
    ) ;
    return ((T)2) * a ;
}

int main( void) {

    int i = 2 ;
    double d = 2.2 ;

    std::cout << i << " : "  << Double(  i) << std::endl ;
    std::cout << d << " : "  << Double(  d) << std::endl ;
    std::cout << &i << " : " << Double( &i) << std::endl ;
}   // fin de fichier
