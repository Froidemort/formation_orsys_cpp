// Fichier './Exemples/Static.cpp'

#include <stdlib.h>
#include <iostream>
using namespace std ;


// Doit etre le premier objet cree, et donc le dernier detruit ----------
static class Application { 
    unsigned int _NbAvions ;
  public :
    Application( void) { _NbAvions = 0 ; }    // Le seul constructeur
    void AvionCree( void) { _NbAvions++ ; }
    void AvionDetruit( void) { _NbAvions-- ; }
    int NbAvions( void) const { return _NbAvions ; }
    ~Application() {
        if ( _NbAvions ) {
            cout << "Il manque " << _NbAvions << " delete" << endl ;
        }
    }
} MonApplication ;


class Avion {  //  ---- Meme classe que l'exemple precedent -------------
    char *N ;
  public:
    ~Avion() { MonApplication.AvionDetruit() ;
          cout << "  < Destruction de " << N << endl ; }
    Avion( char *s) { N=s; MonApplication.AvionCree() ;
          cout << "--> Construction de " << N << endl ; }
} ;




Avion *foo( void ) {
   Avion X( (char *)"X est dans foo()") ;
   static Avion Y( (char *)"Y est static dans foo()") ;
   return new Avion( (char *)"*p dans le tas depuis foo()") ;
}


int main( void) {

   Avion *r = NULL ;
   Avion b( (char *)"b est dans main()") ;
   r = foo() ;
   delete r ;       // Corrige le bogue d'oubli de desallocation
   return 0 ;
}

// Fin de './Exemples/Static.cpp'
