// Fichier './Exemples/Fonc-Inline.cpp'
#include <iostream>
using namespace std ;

inline int foo(int t) { return t; } // definition valant declaration
int goo( int t) { return t; }       // Idem
int hoo( int) ;                     // declaration seule
inline int koo( int) ;              // declaration seule

int main( void) {
   cout << "foo( 66) == " << foo( 66) << endl ; // appel inline
   cout << "goo( 66) == " << goo( 66) << endl ; // appel classique
   cout << "hoo( 66) == " << hoo( 66) << endl ; // appel classique
   cout << "koo( 66) == " << koo( 66) << endl ; // appel inline
   return 0 ;
}

int hoo( int t) { return t ; }        // definition apres appel de hoo
inline int koo( int t) { return t ; } // definition apres appel de koo
                                      // trop tardive pour etre inline
// Fin de './Exemples/Fonc-Inline.cpp'
