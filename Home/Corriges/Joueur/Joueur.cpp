// Fichier './Corriges/Joueur/Joueur.cpp'

#include <iostream>
#include "../Tour/Tour.h"
#include "../Joueur/Joueur.h"

void Joueur::Affiche( void) const {
    std::cout << _Nom << ": score " << score << std::endl ;
}

void Joueur::Joue( void) {

    std::cout << "\n   <--- " << Nom() << " (" << score << ") joue:\n" ;
    Tour T ;

    T.Affiche() ;
    while ( T.score() ) {
        if ( Continue() ) {
            T.nouveau_lancer() ;
            T.Affiche() ;
        } else {
            score += T.score() ;
            break ;
        }
    }
    if ( ! T.score() ) 
        std::cout << "   --- " << Nom() << " a perdu ce tour ------\n"  ;

}

bool JoueurAuto::Continue( void) {
    std::cout << Nom() << " ne prend aucun risque: il ne rejoue pas.\n" ;
    return false ;  // Le joueur automatique ne prend aucun risque
}

bool JoueurManuel::Continue( void) {
    std::cout << "Voulez vous rejouer " << Nom() << " ? " ;
    char s[ 80] ; std::cin >> s ;

    if ( s[ 0] == 'o' || s[ 0] == 'O' )
        return true ;
    return false ;
}

bool JoueurAvise::Continue( void) {
    std::cout << Nom() << ": l'avis du systeme est le suivant:\n" ;
    JoueurAuto::Continue() ;
    std::cout << Nom() << "  mais que fait l'humain ?\n" ;
    return JoueurManuel::Continue() ;
}

// Fin de './Corriges/Joueur/Joueur.cpp'
