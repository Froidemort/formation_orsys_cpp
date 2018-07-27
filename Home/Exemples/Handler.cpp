// Fichier './Exemples/Handler.cpp'

#include <iostream>   // cout cerr set_new_handler()
#include <stdlib.h>   // exit()

using namespace std ;

// Routine de traitement d'erreur
void MaRoutine( 
     void
) {
     cerr << "Allocation memoire impossible" << endl ;
//   return ;   // Provoque une boucle infinie: ou va-t-on ?
     exit( EXIT_FAILURE) ; // Plus efficace que 'return' pour sortir
                           // Utiliser 'abort()' est mieux !
}

int main(
     void
) {
     // Arme MaRoutine()
     set_new_handler( MaRoutine);

     // Provoque un probleme
     long long *pi = new long long[ (size_t)-1];

     // Et reprend l'execution
     cout << "Mais on aura quand meme essaye" << endl ;

     delete [] pi ;
}    // Fin de './Exemples/Handler.cpp'
