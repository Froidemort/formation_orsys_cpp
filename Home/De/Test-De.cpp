// Fichier './De/Test-De.cpp'
// Lien physique './Corriges/De/Test-De.cpp'

#include <iostream>
#include "De.h"

using namespace std ;

int main( void) {

    De D ;          // Un De
	static De E ;   // Un De dans la zone statique

    cout << "Un de tire au hasard  : " << D.valeur() << endl ;
    cout << "Le meme de relance    : " << D.lance()  << endl ;
    cout << "Mais en zone statique : " << E.valeur() << endl ;

    // Un tableau de Des 
    const unsigned int Nb_Des = 10 ;
    cout << endl << "Valeurs dans le tableau de " << Nb_Des << " des" << endl ;
    De d[ Nb_Des] ;

    for ( size_t i=0; i<Nb_Des; i++) {
        if ( i ) cout << "   -   " ;
        cout << "De[" << i << "]: " << d[ i].valeur() ;
    }
    cout << endl ;

    // Mais on n'empeche pas les bogues habituels... ERREUR ci dessous
    cout << endl << "(e2l) Debordement commun d'indice de tableau" << endl ;
    cout << "De[ 10] inexistant: " << d[ 10].valeur() << endl ;

    return 0 ;
}

// Fin de './De/Test-De.cpp'
