// Fichier './Corrige/Fonction/Fonction.cpp'

#include <iostream>
#include <stdio.h>      // Pour sprintf()
using namespace std ;

class Rien {
   char Nom[ 80] ;
public:
   ~Rien() { cout << "<-- Fin de " << Nom << endl ; }
   Rien( const char *s) { sprintf( Nom, "%s", s);
               cout << "--> Cree " << Nom << endl ; }
   Rien( void) { sprintf( Nom, "(vide)");
               cout << "--> Cree " << Nom << endl ; }
   Rien( const Rien &a) { sprintf( Nom, "copie (%s)", a.Nom);
               cout << "--> Cree " << Nom << endl ; }
} ;


Rien &foo( const Rien &) ;


int main( void) {

   Rien a( "a est dans main()") ;
   Rien b ;
   Rien &c = foo( a) ;  // Reference d'un objet fabrique dans le tas
   b = c ;     // b est dans la pile et contient la copie de l'objet du tas
   delete &c ; // detruit l'objet du tas
   return 0 ;
}

Rien &foo( const Rien &r ) {

   Rien x( "x est dans foo()") ;
   return *new Rien( "*p dans le tas") ;
}

// Fin de './Corriges/Fonction/Fonction.cpp'
