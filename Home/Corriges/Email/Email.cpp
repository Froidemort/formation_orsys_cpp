// Fichier './Corriges/Email/Email.cpp'

#include "Email.h"

void VerifierEmail (
     char const *s
) throw( ErreurEmail &) { // L'algorithme n'est pas complet...

    // Il faut une chaine
    if ( !s || ! *s ) throw ChaineVide() ;

    // Il faut une chaine qui ne soit pas de la forme '@.....'
    if ( *s == '@' ) throw NomAbsent() ;

    return ;
}                       // Fin de './Corriges/Email/Email.cpp'
