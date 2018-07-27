// Fichier './Exemples/Toto.cpp'
#include <iostream>      // 'cerr', 'cin'
#include <fstream>       // classe 'ofstream'
#include <cstdio>        // pour perror()
using namespace std ;

int main()
{  ofstream Fichier( "Toto.dbf", ios::app) ;
   if( ! Fichier ) {
       cerr << "Erreur(1) d'ouverture de 'Toto.dbf' - " ; 
       perror( "open()") ;
   } else { // Ne lit pas par '>>' car prend ' ' comme separateur
       char Nom[ 100], Tel[ 100] ;
       cout << "Nom du contact: " ; cin.getline( Nom, 100) ;
       cout << "Num. telephone: " ; cin.getline( Tel, 100) ;
       Fichier << "<contact>\n" ;
       Fichier << "    <nom>" << Nom << "</nom>\n" ;
       Fichier << "    <tel>" << Tel << "</tel>\n" ;
       Fichier << "    </contact>\n\n" ;
   }
}  // Fin de './Exemples/Toto.cpp'
