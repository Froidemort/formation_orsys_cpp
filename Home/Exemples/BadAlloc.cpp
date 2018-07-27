// Fichier './Exemples/BadAlloc.cpp'

#include <iostream>
#include <stdlib.h>    // pour abort()
using namespace std ;

// Routine de traitement d'erreur
void MaRoutine( 
     void
) {
     cerr << "Allocation memoire impossible" << endl ;
     return ; // pour voir, sinon abort() est mieux !
}

int main(
     void
) {
     // Arme MaRoutine()
     set_new_handler( MaRoutine);

     // Provoque un probleme
     long long *pi = new long long[ (unsigned long)-1];

     // Et reprend l'execution
     cout << "Mais on a quand meme essaye" << endl ;
     cout << "Taille de pi : " << sizeof pi << endl ;
     cout << "Taille de *pi : " << sizeof *pi << endl ;

     delete [] pi ; return 0 ;
}    // Fin de './Exemples/BadAlloc.cpp'
