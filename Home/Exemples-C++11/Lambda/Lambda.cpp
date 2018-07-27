// Debut de Home/Exemples-C++11/Lambda/Lambda.cpp
#include <iostream>      // std::cout
#include <functional>    // std::function

// ----------------------------------------------------------------------
// Ci dessous: trailing return type pour la fonction main()             |
// Souvent on peut se passer de l'indication du type "-> int" ; le      |
//         compilateur peut le deduire du 'return'                      |
// En francais on peut traduire par 'syntaxe a la traine'               |
// ----------------------------------------------------------------------

auto main() -> int { // ---------------------------------------------- 73

    // f est de type fonction qui renvoie un 'int' comme souligne '-' 
    auto f = [] ( int const i) -> int { return 2*i; } ;
    //                         ------          ---
    std::cout << "2*7=" << f( 7) << '\n' ;

    // f peut etre copiee dans un pointeur ad hoc
    int (*func_f)( int const) = f ; // 
    std::cout << "2*7=" << (*func_f)( 7) << '\n' ;

    // On peut se passer du nom 'f'
    std::cout << "2*7=" 
              << []( int const i) -> int { return 2*i; }( 7) << '\n' ;

    // Et du type de retour, quand il n'y a pas d'ambiguite
    std::cout << "2*7=" 
              << []( int const i)        { return 2*i; }( 7) << '\n' ;

    // Un adaptateur existe aussi pour manipuler des foncteurs et autres
    std::function< int( int const)> f2 = []( int const i) { return 2*i;};
    std::cout << "2*7=" << f2( 7) << '\n' ;

    // Il est possible de modifier son argument
    int n = 7 ;
    std::function< int( int&)> f3 = []( int& i) { i=2*i; return i;};
    std::cout << "2*7=" << f3( n) << '\n' ;
    std::cout << "  n=" << n << '\n' ;

    return 0 ;
}   // fin de fichier
