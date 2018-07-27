// Fichier './Home/Exemples-C++11/Type_traits/Type_traits.cpp'
#include <iostream>                // std::cout std::boolalpha
#include <type_traits>             // std::is_floating_point< type>
                                   // std::add_const< type> 
class A {};
  
int main( void) { // ------------------------------------------------- 73
    std::cout << std::boolalpha;

    std::cout << std::is_floating_point< A>::value << '\n';
    std::cout << std::is_floating_point< float>::value << '\n';
    std::cout << std::is_floating_point< int>::value << '\n';

    // std::cout << std::is_floating_point< 3.14>::value << '\n';
    // -- ci dessus ne compile pas: 3.14 n'est pas un 'Type'

    typedef std::add_const< double>::type MonConstDouble ;
    std::cout << std::is_floating_point< MonConstDouble>::value << '\n';

}    // fin de fichier
