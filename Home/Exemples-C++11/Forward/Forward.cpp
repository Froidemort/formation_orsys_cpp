// debut de ./Exemples-C++11/Forward/Forward.cpp
#include <iostream>     // std::cout

// 2 variantes de la meme fonction, une pour lvalue, l'autre pour rvalue
void MaFonction( int const& x) { std::cout << " lvalue "; }
void MaFonction( int&&      x) { std::cout << " rvalue "; }

// Une autre fonction intermediaire     // --------------------------- 73
// #define AVEC_TEMPLATE
#ifdef AVEC_TEMPLATE
template< class T>
void Foo(   T&& x) {    // via Foo() la rvalue devient une lvalue
    MaFonction( x);                     // x est toujours vu comme lvalue
    MaFonction( std::forward<   T>( x));// rvalue if argument is rvalue
}   // fin de Foo()
#else
void Foo( int&& x) {    // via Foo() la rvalue devient une lvalue
    MaFonction( x);                     // x est toujours vu comme lvalue
    MaFonction( std::forward< int>( x));// rvalue if argument is rvalue
}   // fin de Foo()
#endif

int main () {  // ---------------------------------------------------- 73
  #ifdef AVEC_TEMPLATE
    std::cout << "\nappel Foo() avec une lvalue:   " ;
    int a; Foo( a);
  #endif
    std::cout << "\nappel Foo() avec une rvalue:   " ;
    Foo( 1);
    std::cout << "\nfin du programme\n" ;
    return 0;
}   // fin de fichier
