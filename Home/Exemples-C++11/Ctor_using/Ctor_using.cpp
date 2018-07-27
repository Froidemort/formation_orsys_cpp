// debut de ./Exemples-C++11/Ctor_using/Cor_using.cpp
#include <iostream>
using std::cout ;

struct B {
    B( void)      { cout << "B::B()\n"     ; }
    B( int)       { cout << "B::B( int)\n" ; }
    B( B const&)  { cout << "B::B( B const&)\n" ; }
    int f( int)   { return 12 ; }
    int f( float) { return 13 ; }
} ;

struct C : B {
    using B::B ;        // Herite de tous les constructeurs
    using B::f ;        // Herite de toutes les fonctions int f() 
//  C( void) { cout << "C::C()\n" ; }             // -2-
//  C( int)  { cout << "C::C( int)\n" ; }         // -1-
} ;

int main() { // ----------------------------------------------------70
    C c1 ;
    C c2( 8) ;
    C c3( c2) ;
    cout << "\nfin du programme\n" ;
}
// fin de fichier
