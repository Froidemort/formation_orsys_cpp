// Fichier './Exemples/ZeroCatch.cpp'

// Tous les messages commencent par "(debug)"

#include <iostream>
using namespace std ;

void goo( void ) {
    cerr << "(debug) avant erreur dans goo()\n" ;
    int i=9 ; int j=1 ; cerr <<"(debug) " << i / --j << endl ; // oups !
    cerr << "(debug) apres erreur dans goo()\n" ;
}

void foo( void ) {
    cerr << "(debug) avant erreur dans foo()\n" ;
    int i=9 ; int j=1 ;
    if ( j==1 ) throw "Division par zero" ;
    else cerr << "(debug) " << i / --j << endl ; // oups !
    cerr << "(debug) apres erreur dans foo()\n" ;
}

// Une erreur (ici une division maladroite) n'est pas une exception
// Une exception DOIT etre generee par throw pour etre traitee dans catch

int main( void) {

    try { foo() ; }
    catch( char const *s ) {
        cerr << "(debug) Exception traitee : " << s << endl ;
    } catch( ... ) {
        cerr << "(debug) Une exception est traitee\n" ;
    }

    cerr << endl ;

    try { goo() ; } catch( ... ) {
        cerr << "(debug) L'exception est traitee\n" ;
    }

    cerr << "(debug) Fin normale du programme\n" ; return 0 ;
}   // Fin de './Exemples/ZeroCatch.cpp'
