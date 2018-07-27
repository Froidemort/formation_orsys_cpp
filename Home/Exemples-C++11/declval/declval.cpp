// debut de ./Exemples-C++11/declval/declval.cpp
#include <utility>          // std::declval<>
#include <iostream>         // std::cout

struct T {
    T( T const& x) {} // Seul constructeur: on ne peut rien fabriquer
    virtual int a( void)=0 ; // Classe abstraite: on ne peut pas ...
} ;

int main() { // -------------------------------------------------- 70

//    decltype( T::a()) i ;    i=8;
//    error: cannot call member function 'int T::a()' without object

//    decltype( T().a()) i ;
//    error: allocating an object of abstract class type 'T'
// ou error: no matching constructor for initialization of 'T'

    decltype( std::declval< T>().a()) i ; i=9 ;

    std::cout << "\nfin du programme avec i==" << i << '\n' ;
}
// fin de fichier
