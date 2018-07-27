// Fichier './Corriges/Cercle/Test.cpp'

#include "Cercle.h"

int main( void) {

   Cercle a( 1, 1, 1) ;

   (*(Point *)&a).Affiche() ;
   (*(Point *)&a).Bouge( 1, 1) ;
   (*(Point *)&a).Affiche() ;

   return 0 ;
}
// Fin de './Corriges/Cercle/Test.cpp'
