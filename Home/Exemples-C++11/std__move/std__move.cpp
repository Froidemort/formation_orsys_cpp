// Debut de Home/Exemples-C++11/std__move/std__move.cpp
// foo,bar selon https://fr.wikipedia.org/wiki/Variable_metasyntaxique
#include <iostream>   // std::cout
#include <memory>     // std::move std::unique_ptr



void Affiche( std::unique_ptr< int> const& x, char const* s) noexcept
{
    std::cout << s ;
    if ( x ) std::cout << *x << '\n'; else std::cout << "vide\n";
}   // fin de Affiche()



int main () { // -------------------------------------------------- 70

    std::unique_ptr< int> foo ;
    Affiche( foo,"foo initialement: ") ;

    foo = std::unique_ptr< int>( new int( 666)) ;
    Affiche( foo, "foo apres deplacement dans foo d'une rvalue: ") ;

    std::unique_ptr< int> bar ;
    // bar = foo ; // ne compile pas: error: use of deleted function
    bar = std::move( foo) ;
    Affiche( foo, "foo apres deplacement dans bar: ") ;
    Affiche( bar, "bar apres std::move(): ") ;

    // int* p = foo ;   // --> Ne compile pas
    // error: cannot convert 'std::unique_ptr<int>' to 'int*'

    // int& r = *foo ;  // --> Compile mais violation de segmentation
    // std::cout << "r reference int& de *foo: " << r << '\n' ;

    std::unique_ptr< int> baz = std::unique_ptr< int>( new int( 777));
    Affiche( baz, "baz apres deplacement dans baz d'une rvalue: ") ;
    baz = std::move( bar) ;
    Affiche( bar, "bar apres deplacement dans bar: ") ;
    Affiche( baz, "baz apres deplacement dans baz: ") ;
    // La desallocation de l'ancien baz se fait bien selon valgrind

}   // fin de fichier
