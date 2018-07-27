// Fichier './Corriges/Email/Test.cpp'

#include <stdio.h>
#include "Email.h"

int main(
    void
) {
    char s[ 80] ;

    while ( 1 ) {
        
        printf( "Saisissez une adresse email: ") ;
        gets( s) ;

        try { VerifierEmail( s) ; printf( " -->    OK: L'adresse est enregistree\n") ; }
        catch( ErreurSaisie &e) { printf(  " --> ERROR: %s\n", e.what()) ; }
    }
    return 0 ;
}   // Fin de './Corriges/Email/Test.cpp'
