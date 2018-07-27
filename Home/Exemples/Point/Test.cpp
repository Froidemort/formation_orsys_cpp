// Fichier './Exemples/Point/Test-Point.cpp'

#include "Point.h"

int main( void) {

   Point a, b;

   a.Place( 1, 2);
   b.Place( 3, -5);
   a.Affiche();
   b.Affiche();
   a.Bouge( 1, 1);
   a.Affiche();

   return 0 ;
}  // Fin de './Exemples/Point/Test-Point.cpp'
