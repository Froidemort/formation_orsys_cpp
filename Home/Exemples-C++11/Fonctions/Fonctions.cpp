// Fichier './Home/Exemples-C++11/Fonctions/Fonctions.cpp'
#include <iostream>        // std::cout std::endl

template < class A, class B>
auto Somme( A const& a, B const& b) -> decltype( a+b) {
    return a+b ;
}

int main() {   // ------------------------------------------------- 70
    int i=8 ; double x = 10.15 ;
    std::cout << i << " + " << x << " = " << Somme( i, x) << '\n' ;
}   // fin de fichier
