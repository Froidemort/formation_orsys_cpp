// Fichier './Exemples/Open.cpp'

#include <iostream>      // cerr
#include <fstream>       // classe ifstream
#include <string>        // classe string et c_str()
#include <cstdio>        // perror()
using namespace std ;

int main( void)
{
   #if defined( __linux__)
       #include <locale.h>
       setlocale( LC_ALL, "") ;
   #endif
   string MonFich( "Gillain.dbf") ; ifstream Fichier ;
 

   Fichier.open( MonFich.c_str(), ios::in) ;
   if( ! Fichier ) {
       cerr << "Erreur(1) d'ouverture de " << MonFich << ':' ;
       perror( " open()") ;
   } else Fichier.close() ;


   Fichier.clear() ;   // Necessaire pour 'effacer' l'erreur
   Fichier.exceptions( ifstream::failbit | ifstream::badbit) ;
   try {
       Fichier.open( MonFich.c_str(), ios::in) ;
       Fichier.close() ;
   } catch ( ifstream::failure &e ) {
       cerr << "Erreur(2) d'ouverture de " << MonFich << endl ;
   } catch ( ...) {
       cerr << "Erreur(3) d'ouverture de " << MonFich << endl ;
   }

   return 0 ;
}                          // Fin de './Exemples/Open.cpp'
