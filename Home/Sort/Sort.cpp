// Debut de Home/Sort/Sort.cpp
#include <iostream>       // std::cout
#include <tuple>          // std::tuple
#include <vector>         // std::vector
#include <algorithm>      // std::sort

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

    // liste tous les contacts selon leur indice dans MesContacts
    ecrivez votre code a base de std::for_each et d'une fonction lambda
	de faon a recuperer ce code dans les 3 points suivants

    // liste tous les contacts tries par prenom
    ecrivez votre code a base de std::sort et d'une fonction lambda

    // liste tous les contacts tries par age
    ecrivez votre code a base de std::sort et d'une fonction lambda

    // liste tous les contacts tries par salaire
    ecrivez votre code a base de std::sort et d'une fonction lambda

}   // end of file
