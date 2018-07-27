// Debut ./Home/Exemples-C++11/tuple
#include <tuple>      // std::make_tuple() std::get<>
#include <iostream>   // std::cout

int main() { // --------------------------------------------------- 70

    auto UnContact = std::make_tuple( 
            "Denis", 59, 888.88, "denis.gillain@ellipsys.fr"
         ) ;
    std::cout << "\nUn contact a " ;
    std::cout << std::tuple_size< decltype( UnContact)>::value ;
    std::cout << " champs\n\n" ;

    // std::get< indice> avec indice >=0
    // et indice <= std::tuple_size< decltype( UnContact)>::value
    std::cout << "nom:     " << std::get< 0>( UnContact) << '\n' ;
    std::cout << "salaire: " << std::get< 2>( UnContact) << "\n\n" ;
//  std::cout << "erreur de compilation " << std::get< 4>( UnContact);
//  invalid use of type 'class std::tuple_element<0ul, std::tuple<> >

    auto AutreContact = std::make_tuple(
            "Victoria", std::ignore, std::ignore, "esther@ellipsys.fr"
         ) ;
    std::cout << "nom:     " << std::get< 0>( AutreContact) << '\n' ;
//  std::cout << "salaire: " << std::get< 2>( AutreContact) << "\n\n";
//  error: no match for 'operator<<' a cause de std::ignore
}   // fin de fichier
