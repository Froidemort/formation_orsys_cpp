// Fichier './Exemples/Explicit.cpp'
#include <iostream>
using namespace std ;

class Point {
  private : 
    int x, y ;
  public :
    Point( void)
      { cout << "constructeur vide\n" ; x=y=0; }
    explicit Point( int a)
      { cout << "constructeur de conversion\n" ; x=y=a; }
} ;

int main( void) {

    Point A ;       // constructeur vide
    Point B( 5) ;   // constructeur de conversion: mention explicite
//  Point C = 2 ;   // appel implicite au constructeur de conversion
                    // ne compile pas car le constructeur est 'explicit'
//  A = 3 ;         // idem (la conversion implicite est preferable)
    return 0 ;
}                   // Fin de './Exemples/Explicit.cpp'
