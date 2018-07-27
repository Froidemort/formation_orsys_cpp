// Debut de ./Fonction/Fonction.cpp

#include <iostream>
#include <stdio.h>      // Pour sprintf() de Linux ou sprintf_s() sinon
using namespace std ;	// A eviter: obsolete. Preferer 'std::cout' ...
#include <string>

class Rien {
   string Nom ;
public:
   ~Rien() { cout << "<-- Fin de " << Nom << endl ; }
   Rien( string const &s) {
   Nom.assign(s) ;
	cout << "--> Cree " << Nom << endl ;
   }
   Rien(const Rien &r) {Nom.assign("Copie de \""+r.Nom+"\"");} 
   Rien(): Rien("VOID"){}
} ;


Rien& foo(Rien &r) ;    // Ne pas modifier cette ligne


int main( void) {

   Rien a( "a est dans main()") ;
   Rien b ;
   Rien& c = foo( a) ;
   delete &c;
   cout << "    apres appel a foo()\n" ;
   return 0 ;
}

Rien& foo( Rien &r) {

   Rien x( "x est dans foo()") ;
   return *new Rien( "*p dans le tas") ;
}

// fin de ./Fonction/Fonction.cpp
