// Debut de Home/Sort/Sort.cpp
#include <iostream>       // std::cout
#include <tuple>          // std::tuple
#include <vector>         // std::vector
#include <algorithm>      // std::sort

                    // nom,      age, salaire
typedef std::tuple< std::string, int, float> Contact_t ;
    // nom, age, salaire
typedef std::vector< Contact_t>              Carnet_t  ;


inline void Liste( Carnet_t const& Car) {  // --------------------- 70
    for_each( Car.cbegin(), Car.cend(), [ ] ( auto const& contact) {
            std::cout << "   " << std::get< 0>( contact) << ' ' ;
            std::cout          << std::get< 1>( contact) << ' ' ;
            std::cout          << std::get< 2>( contact) << std::endl;
        }
    ) ;
}


auto main() -> int { // ------------------------------------------- 70

    Carnet_t MesContacts{
        Contact_t{ "Charlie",  10, 0.0},
        Contact_t{ "Mylene",   50, 2400.0},
        Contact_t{ "Victoria", 46, 1600.0},
        Contact_t{ "Mathieu",  27, 2222.0},
        Contact_t{ "Denis",    59, 1000.0},
        Contact_t{ "Tania",    23, 552.0}
    } ;

// liste tous les contacts selon leur indice dans MesContacts
    std::cout << "Ordre a la creation\n" ;
    Liste( MesContacts) ;

// liste tous les contacts tries par prenom
    std::sort( MesContacts.begin(), MesContacts.end(), 
        []( Contact_t& a, Contact_t& b) {
            return std::get< 0>( a) < std::get< 0>( b) ;
        }
    ) ;
    std::cout << "\nTrie sur les noms\n" ;
    Liste( MesContacts) ;

// liste tous les contacts tries par age
    std::sort( MesContacts.begin(), MesContacts.end(), 
        []( Contact_t& a, Contact_t& b) { // Seul changement: 0->1
            return std::get< 1>( a) < std::get< 1>( b) ;
        }
    ) ;
    std::cout << "\nTrie sur les ages\n" ;
    Liste( MesContacts) ;

// liste tous les contacts tries par salaire
    std::sort( MesContacts.begin(), MesContacts.end(), 
        []( Contact_t& a, Contact_t& b) { // Seul changement: 0->1
            return std::get< 2>( a) < std::get< 2>( b) ;
        }
    ) ;
    std::cout << "\nTrie sur les salaires\n" ;
    Liste( MesContacts) ;

}   // end of file
