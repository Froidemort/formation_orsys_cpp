// Debut de Home/Exemples-C++11/std__find_if/std__find_if.cpp
#include <iostream>       // std::cout
#include <tuple>          // std::tuple
#include <vector>         // std::vector
#include <algorithm>      // std::find_if

                    // nom,      age, salaire
typedef std::tuple< std::string, int, float> Contact_t ;
    // nom, age, salaire
typedef std::vector< Contact_t>              Carnet_t  ;

auto main() -> int { // ---------------------------------------------- 73

    Carnet_t MesContacts{
        Contact_t{ "Charlie",  10, 0.0},
        Contact_t{ "Mylene",   50, 2400.0},
        Contact_t{ "Victoria", 46, 1600.0},
        Contact_t{ "Mathieu",  27, 2222.0},
        Contact_t{ "Denis",    59, 1000.0},
        Contact_t{ "Tania",    23, 552.0}
    } ;

    // liste tous les contacts de plus de 50 ans:
    auto pUnContact = MesContacts.cbegin() ; // ie. 'Carnet_t::iterator'
    unsigned int nb = 0 ;
    int Age = 50 ;
    for (;;) {

        pUnContact = std::find_if(
            pUnContact, MesContacts.cend(),
            [ &nb, Age ]( auto contact) ->bool {
                // std::cerr << "# " << std::get< 0>( contact) << '\n' ;
                if ( std::get< 1>( contact) < Age ) return false ;
                nb++ ;
                return true ;
            }
         ) ;

        if ( pUnContact == MesContacts.cend() ) break ;
        std::cout << std::get< 0>( *pUnContact) << " a " ;
        std::cout << std::get< 1>( *pUnContact) << " ans" << '\n' ;
        ++pUnContact ;
    }

    if ( ! nb ) return 1 ;
    std::cout << nb << " contact(s) trouves\n" ; return 0 ;
}   // end of file
