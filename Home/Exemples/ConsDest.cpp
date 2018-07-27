// Fichier './Exemples/ConsDest.cpp'
#include <iostream>
using namespace std ;

class Avion {
    const char *N ;
  public:
    ~Avion() { cout << "  < Destruction de " << N << endl ; }
    Avion( const char *s) { N=s ;
           cout<<"--> Construction de "<< N <<endl ; }
} ;

void foo( void) ;
Avion a( "a est global") ;

int main( void) {

   Avion *pa = (Avion *)0 ;
   const Avion b( "b est dans main()") ;    // ou Avion const b( ....
   foo() ;
   { Avion const c( "c est entre {} dans main()") ; }
   Avion TroisAvions[ 3] = 
      { Avion( "t1"), Avion( "t2"), Avion( "t3") } ;
   foo() ;
   return 0 ;
}

void foo( void ) {
   Avion X( "X est dans foo()") ;
   static Avion Y( "Y est static dans foo()") ;
   Avion * const p = new Avion( "*p dans le tas depuis foo()") ;
           // p est 'const' pas l'avion qui peut changer lui
}          // Fin de  './Exemples/ConsDest.cpp'
