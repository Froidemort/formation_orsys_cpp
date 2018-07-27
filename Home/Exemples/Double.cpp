// Fichier './Exemples/Double.cpp'

#include <iostream>
using namespace std ;

class A 
{
  public:
     template <class T> T Double(T t) ;
     template <class T> static T Triple(T t) ;
     template <class T> inline T Quad(T t) ;
} ; 

template <class T> T A::Double(T t) { return t*2; }
template <class T> T A::Triple(T t) { return t*3; }
template <class T> inline T A::Quad(T t) { return t*4; }

// NB: on ne doit pas specifier static pour la definition, 
//     la declaration est suffisante et fait l'affaire

int main( void) {

   A a ;

   cout << "double( 6)==" << a.Double( 6) << endl ;
   cout << "double( .1)==" << a.Double( .1) << endl ;
   cout << "triple( 5.2)==" << A::Triple( 5.2) << endl ; // car static
   cout << "quad( '?')==" << a.Quad( '?') << endl ;
   cout << "quad( (int)'?')==" << a.Quad( (int)'?') << endl ;

   return 0 ;
}                                    // Fin de './Exemples/Double.cpp'
