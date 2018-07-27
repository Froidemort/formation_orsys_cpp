// Fichier './Exemples/Salaire.cpp'

#include <iostream>         // pour cerr cout
#include <cstdlib>          // pour abort()
#include "Erreur.h"         // pour la classe Erreur


double CalculSalaire(       // Calcule le salaire d'un animateur
     char const *nom
) /* throw( Erreur ) */ {   // Spec. obsolete entre /*  ... */
//    ...........
//   if ( Salaire < 0 )
        throw Erreur( ErrSalaireNegatif, nom, 887624436) ;
//      .........
}

int main( void) {
    try {
          std::cout << "Salaire: " << CalculSalaire( "Gillain") ;

    } catch ( Erreur &e) {
          std::cerr << "Erreur numero: " << e.getNum() << std::endl ;
          std::cerr << "Animateur    : " << e.what() << std::endl ;
          std::cerr << "Magic number : " << e.getMagic() << std::endl ;
          std::cerr << std::endl ; abort() ; 
    }

    return 0 ;
}                    // Fin de './Exemples/Salaire.cpp'
