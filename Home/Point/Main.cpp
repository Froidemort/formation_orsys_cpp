// Fichier './Point/Main.cpp'
// Fichier './Corriges/Point/Main.cpp'

#include "Point.h"

unsigned int Point::SequenceId = 0 ;

int main( void) {

   Point a( 1, 2); a.Affiche( "1, 2");
   Point b( 3.92, -5.2); b.Affiche( "3.92, -5.2");
   Point c( 3.92, -5.99999); c.Affiche( "3.92, -5.99999");
   Point d( 3, 5.5); d.Affiche( "3, 5.5");
   Point e( 3.51, -5); e.Affiche( "3.51, -5");

   Point aa( a) ; aa.Affiche( "copie de a") ;
   Point bb ; bb.Affiche( "constructeur vide") ;

   // Il manque la surcharge de l'affectation !
   bb = a ; bb.Affiche( "ERREUR sauf si surcharge de =") ;

   // Combien de 'Point' sont crees ?
   Point p ; p = Point( 5, 6) ; 
   Point q ;
   p.Affiche( "p vide") ; q.Affiche( "q vide") ;

   return 0;
}

// Fin de './Point/Main.cpp'
