// Fichier 'Home/Corriges/Point/Point.h'

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED


class Point {
      int x, y ;
      unsigned int Id ;
      static unsigned int SequenceId ;
  public :
      Point( int a=0, int b=0) { x=a; y=b; Id=SequenceId++ ;}
      Point( const Point &r) { x=r.x; y=r.y; Id=SequenceId++ ;}
      ~Point() {}
      void Deplace( int dx, int dy) { x+=dx; y+=dy; }
      void Affiche( const char* const s=(const char* const)0) const;
      Point& operator=( const Point& r) { x=r.x;y=r.y;return *this;}
} ;


#endif                  // fin de 'Home/Corriges/Point/Point.h'
