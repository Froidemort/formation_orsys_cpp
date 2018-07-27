// Fichier './Exemples/Cercle/Point.h'
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point {
      int x, y ;
public:
      int X( void) const { return x; }
      int Y( void) const { return y; }
      Point( int a, int b) { x=a ; y=b; }
      void Place( int, int) ;
      void Bouge( int, int) ;
      void Affiche( void) ;
} ;

#endif
// Fin de './Exemples/Cercle/Point.h'
