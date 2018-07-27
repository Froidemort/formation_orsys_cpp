// Fichier './Exemples/Cercle/Test.cpp'

#include "Cercle.h"

int main( void) ;

int main( void) {

   Cercle a( 1, 1, 1), b ;

   a.Affiche() ;
   a.Bouge( 1, 1) ;
   a.Affiche() ;

   b.Place( 10, 10) ; b.Affiche() ;
   b = a ; b.Affiche() ;

   Cercle c( a) ; c.Affiche() ;
   return 0 ;
}  // Fin de './Exemples/Cercle/Test.cpp'
