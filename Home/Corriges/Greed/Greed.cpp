// Fichier './Corriges/Greed/Greed.cpp'

#include "../Joueur/Joueur.h"

#include <vector>
#include <iostream>

int main(
    void
) {
    std::vector< Joueur* > MesJoueurs ;

    MesJoueurs.push_back( new JoueurManuel( "Denis")) ;
    MesJoueurs.push_back( new JoueurAuto( "Big Blue")) ;

    std::cout << "Il y a " << (int)MesJoueurs.size() << " joueurs.\n";

    std::vector< Joueur* >::iterator it;
    bool FinDePartie = false ;
    while ( ! FinDePartie ) {

        for (
                it = MesJoueurs.begin() ;
                it < MesJoueurs.end() ; 
                it++
        ) {
            (*it)->Joue() ;

            if ( (*it)->Gagne() ) {
                std::cout << (*it)->Nom() << " gagne !\n" ;
                FinDePartie = true ;
            }
        }
    }

    for ( it = MesJoueurs.begin() ; it < MesJoueurs.end() ; it++ ) {
        (*it)->Affiche() ;
        delete *it ;
    }

    return 0;
}                          // Fin de './Corriges/Greed/Greed.cpp'
