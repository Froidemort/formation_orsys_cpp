// Fichier './Exemples/Dessin/Test.cpp'

#include "Image.h"
#include "DessinCercle.h"

int main( void) {

   Image i( "./Dessin.svg") ; // Une image est un fichier '.svg'

   // constructeur ( position x, position y, rayon, couleur) 
   DessinCercle a( 120, 120, 30 ) ;
   DessinCercle b( 40, 40, 20, vert) ;

   i.Dessine( a) ;
   i.Dessine( b) ;
   b.Bouge( 80, 0) ; i.Dessine( b) ;
   b.Bouge( 80, 0) ; i.Dessine( b) ;

   return 0 ;
}  // Fin de './Exemples/Dessin/Test.cpp'
