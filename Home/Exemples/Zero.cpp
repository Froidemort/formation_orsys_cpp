// Fichier './Exemples/Zero.cpp'

#include <iostream>
using namespace std ;

void goo( void ) {
    cerr << "avant erreur dans goo()\n" ;
    int i=9 ; int j=1 ; cerr << i / --j << endl ; // oups !
    cerr << "apres erreur dans goo()\n" ;
}

// Quel code retour pour le shell ?
// Sous Linux 136 car 128+8 (SIGFPE==8)

int main( void) {

    goo() ;
    cerr << "Fin normale du programme\n" ; return 0 ;
}   // Fin de './Exemples/Zero.cpp'
