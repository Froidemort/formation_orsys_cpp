// Fichier './Home/Exemples-C++11/Initialiseur/Initialiseur.cpp'
#include <iostream>

class C {
  public:
    C( void) { std::cout << "Constructeur vide\n" ; }
    C( int i) { std::cout << "Constructeur a un 'int'\n" ; }

    // Ne compile pas: call of overloaded 'C(int)' is ambiguous
//  C( int i, ...) { std::cout << "Constructeur a liste\n" ;}

    C( std::initializer_list< int> liste) {
        std::cout << "Constructeur a liste\n" ;
        for ( const auto e : liste ) {
            std::cout << e << '-' ;
        }
        std::cout << std::endl ;
    }
} ;    // fin de class C

int main( void) {  // ------------------------------------------------ 73
    C a, c( 78);
//  C b( 10,9,8); // no matching function for call to C::C(int,int,int)
//  C b( std::initializer_list< int>( 10,9,8));  // Pas de constructeur
    C b( std::initializer_list< int>{ 10,9,8});  // Solution du C++11
    C e{ 10,9,8}; // Identique en plus court
    C d{ 77};     // Appel explicite du constructeur a liste
    C f{};        // Mais appel au constructeur vide par contre !
//  C g();        // Compile mais ne donne aucune execution !
}   // fin de fichier
