// Fichier 'Home/Point/Point.h'
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>     /* getpid() */


class Point {
   private:
   	int _x,_y ;
    unsigned int Id ;
    static unsigned int SequenceId ;

   public:
   	Point(Point const &p) {Id=SequenceId++ ;};
   	Point(int x, int y) : _x(x), _y(y) {Id=SequenceId++ ;};
   	Point(double x, int y) : _x(x), _y(y) {Id=SequenceId++ ;};
   	Point(int x, double y) : _x(x), _y(y) {Id=SequenceId++ ;};
   	Point(double x, double y) : _x(x), _y(y) {Id=SequenceId++ ;};
   	Point(): Point(0,0) {Id=SequenceId++ ;} ;
   	~Point() {} ;
   	void Affiche(char const * message) const ;
   	int get_abcisse(void) const {return _x;};
   	int get_ordonnee(void) const {return _y;};
   	void set_abcisse(int x) {_x = x;};
   	void set_ordonnee(int y) {_y = y;};
   	Point& operator=( const Point& p) {
   		if (&p != this) {_x=p._x;_y=p._y;}
   		return *this;
   	}

} ;

#endif      // fin de 'Home/Point/Point.h'
