// Fichier './Joueur/Greed.cpp'
// Fichier './Corriges/Joueur/Greed.cpp'

#define GREED_CPP_FILE
#include "../Joueur/Joueur.h"
#include <iostream>

int main(
    void
) {
    const size_t NbJoueurs = 2 ;  // Cree un tableau de 2 joueurs
    Joueur *j[ NbJoueurs] ;
//  j[ 0] = new JoueurAvise( "Big Denis") ;
    j[ 0] = new JoueurManuel( "Denis") ;
    j[ 1] = new JoueurAuto( "Big Blue") ;

    size_t i ; bool FinDePartie = false ;
    while ( ! FinDePartie ) {

        for ( i=0; i<NbJoueurs; i++) {// Tous les joueurs disposent
            j[ i]->Joue() ;           // du meme nombre de tours

            if ( j[ i]->Gagne() ) {
                std::cout << j[ i]->Nom() << " gagne !\n" ;
                FinDePartie = true ;
            }
        }
    }

    for ( i=0; i<NbJoueurs; i++) { // Affiche tous les scores:
        j[ i]->Affiche() ;
        delete j[ i] ;             // et detruit tous les joueurs
    }

    return 0;
}                                  // Fin de './Joueur/Greed.cpp'
