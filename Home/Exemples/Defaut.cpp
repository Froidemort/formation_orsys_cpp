#include <stdlib.h> // Fichier './Exemples/Defaut.cpp'

#include <iostream>
using namespace std ;

// Prototype obligatoire en C++ ----------------------
void Affiche( const char *, int =10) ; 

// Definition de la fonction -------------------------
void Affiche(
     const char *valeur,
     int base
) {
     cout << strtol( valeur, NULL, base) << endl ;
}

// Programme pour le test ----------------------------
int main( void) 
{    // 16 en binaire s'ecrit 10000
     Affiche( "10000") ;      // affiche 10000
     Affiche( "10000", 2) ;   // affiche 16
     return 0 ;
}                    // Fin de './Exemples/Defaut.cpp'
