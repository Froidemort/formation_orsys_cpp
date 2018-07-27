// Fichier './Exemples/Throw.cpp'

#include <iostream>
using namespace std ;

void goo( void ) {
    cerr << "avant exception dans goo()\n" ;
    throw "erreur de goo" ;
    cerr << "apres exception dans goo()\n" ;
}

void foo( void ) {
    cerr << "avant exception dans foo()\n" ;
    goo() ;
    cerr << "apres exception dans foo()\n" ;
}


int main( void) {
#ifdef __linux__
    std::setlocale( LC_ALL, "") ; // la libstdc++ n'a pas traduit
#endif                            // le message qui reste en anglais

    foo() ;
    cerr << "Fin normale du programme\n" ; return 0 ;

}   // Fin de './Exemples/Throw.cpp'
