// Fichier './Exemples-C++11/assert/assert.cpp'

// #define NDEBUG    // pour desactiver assert(), otez le commentaire
#include <assert.h>  // pour assert()
#include <stdio.h>   // pour printf(), scanf()

int main( void)
{
    int i = 10 ;
    printf( "tapez un chiffre: ") ;
    scanf( "%d", &i) ;

    assert( i>=0 && i <=9) ;
    printf( "Saisie d'un chiffre... reussie\n") ;
    return 0 ;
}   // Fin de fichier
