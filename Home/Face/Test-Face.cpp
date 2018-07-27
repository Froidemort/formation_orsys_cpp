// Debut de './Face/Test-Face.cpp'
// Lien physique './Corriges/Face/Test-Face.cpp'

#include <iostream>
#include "Face.h"

using namespace std ;

int main( void) {

    const size_t Nb_Des = 5 ;
    De d[ Nb_Des] ;

    // Compile ci dessous avec un Warning (simple verification: fournit un 'warning')
    De::Face face ; // Combien vaut une variable 'face' creee dans la pile ?
    cout << "Valeur (aleatoire) d'une face sans initialisation: " << face << " ." << endl ;
    // Pour interdire l'instruction ci dessus, on peut mettre le constructeur de Face vide en private

    // Mais cela n'empeche toujours pas les debordements ...
    cout << endl << "On n'empeche pas un debordement ordinaire d'indice de tableau..." << endl ;

    for ( size_t i=0; i<Nb_Des+5; i++) {     // +5 pour deborder 5 fois
        if ( i ) cout << "  -  " ;
        cout << "De(" << i << "): " << d[ i].valeur() ;
    }
    cout << endl ;

    // Mais le controle de type est renforce a la compilation: l'instruction suivante n'est pas autorisee
    // face = 5 ;
    return 0 ;
}   // fin de './Face/Test-Face.cpp'
