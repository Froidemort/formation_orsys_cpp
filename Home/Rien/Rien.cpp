// Fichier './Home/Rien/Rien.cpp'

#ifdef __linux__
    #include <unistd.h> // pour sleep() version unix
#else
    #include <windows.h> // pour Sleep() version windows
#endif

#include <iostream>
// #include <stdlib.h>      // pour exit() ou aussi:
// #include <cstdlib>       // pour std::exit()
using namespace std ;

class Rien {
   const char *Nom ;
public:
   inline ~Rien() { cout << "  < Fin de " << Nom << endl ; }
   inline Rien( const char *s) { Nom=s; cout << "--> Cree   " << Nom << endl ; }
} ;


void foo( void) ;


// Definition globale
Rien a( "a est global"), b( "b est global") ;

int main( void) {

   // Variable locale
   Rien c( "c est dans main()") ;
   {
      Rien d( "d est dans {}") ;
   }
   Rien e( "e est dans main()") ;
   foo() ;
   Rien f( "f est dans main()") ;

   Rien TroisFoisRien[ 3] = 
      { Rien( "t1"), Rien( "t2"), Rien( "t3") } ;

   static Rien g( "g static dans main()") ;
//   sleep( 100) ; // pour tester le Ctrl-C depuis UNIX
//   Sleep( 100000L) ; // pour un arret premature sous windows

   // Rien i ; 
   // Rien j( c) ; // Pas de constructeur de copie: membre a membre

//   exit(0) ;
   return 0 ;
}

void foo( void ) {
   Rien h( "h est dans foo()") ;
   static Rien i( "i static dans foo()") ;
   Rien *p ;

   p = new Rien( "*p dans le tas") ;

   delete p ;
   p = nullptr;
}

// Fin de './Home/Rien/Rien.cpp'
