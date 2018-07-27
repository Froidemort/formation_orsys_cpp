// Fichier './Exemples/Point/Point.h'
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point {
  public :
      void Place( int, int) ;
      void Bouge( int, int) ;
      void Affiche( void) const ;
  private : 
      int x, y ;
} ;

#endif    // Fin de './Exemples/Point/Point.h'
