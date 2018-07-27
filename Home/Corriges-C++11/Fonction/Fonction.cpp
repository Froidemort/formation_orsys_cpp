// Debut de ./Corriges-C++11/Fonction/Fonction.cpp
#include <iostream>
#include <stdio.h>    // Pour sprintf() de Linux ou sprintf_s() sinon
using namespace std ; // A eviter: obsolete. Preferer 'std::cout' ...

class Rien { // --------------------------------------------------- 70
   char Nom[ 80] ;
public:
   ~Rien() { cout << "<-- Fin de " << Nom << endl ; }
   Rien( char const* s) {
   #if defined( __linux__)
      sprintf( Nom, "%s", s);
   #else
      sprintf_s( Nom, 80, "%s", s); Nom[ 79]='\0' ;
   #endif
      cout << "--> Cree " << Nom << endl ;
   }

   Rien( void) {
   #if defined( __linux__)
      sprintf( Nom, "%s", "(objet vide)");
   #else
      sprintf_s( Nom, 80, "%s", "(objet vide)"); Nom[ 79]='\0' ;
   #endif
      cout << "--> Cree " << Nom << endl ;
   }

   Rien( Rien&& r) {
   #if defined( __linux__)
      sprintf( Nom, "Deplacement de %s", r.Nom);
   #else
      sprintf_s( Nom, 80, "Deplacement de %s", r.Nom); Nom[ 79]='\0' ;
   #endif
      cout << "--> Deplace " << Nom << endl ;
   }
} ;


Rien& foo( Rien r) ;    // Ne pas modifier cette ligne
// Rien& foo( Rien const& r) ;    // est une bien meilleure solution


int main( void) { // ---------------------------------------------- 70
   Rien a( "a est dans main()") ;
   Rien& b = foo( Rien( "rhs")) ;
   cout << "    apres appel a foo()\n" ;
   delete &b ;
   return 0 ;
}

Rien& foo( Rien r) {
   Rien x( "x est dans foo()") ;
   return *new Rien( "*p dans le tas") ;
}
// fin de fichier
