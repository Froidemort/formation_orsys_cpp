#include "../include/Joueur.h"

#include <vector>
#include <iostream>
#include <string>


int main(
    void
) {
    std::vector< Joueur* > MyPlayers ;

    MyPlayers.push_back( new JoueurManuel("Denis")) ;
    MyPlayers.push_back( new JoueurAuto( "Big Blue")) ;

    std::cout << "Il y a " << (int)MyPlayers.size() << " joueurs.\n";

    bool FinDePartie = false ;
    while ( ! FinDePartie ) {

        for (auto it = MyPlayers.begin() ; it < MyPlayers.end() ; it++) {
            std::cout << "Player :" << (*it)->Nom() << std::endl;
            (*it)->Joue() ; // Boucle sur le tour
            std::cout << "Current player :"<< (*it)->Nom() <<" with current score : " << (*it)->score() << std::endl;
            std::cout << "-----------------------------------------------------\n" ;

            if ( (*it)->Gagne() ) {
                std::cout << "The player "<<  (*it)->Nom() << " gagne !\n" ;
                FinDePartie = true ;
                break;
            }
        }
    }
    std::cout << "-----------------------------------------------------\n" ;
    for (auto it = MyPlayers.cbegin() ; it < MyPlayers.end() ; it++ ) {
        (*it)->Affiche() ;
        delete *it ;
    }

    return 0;
}