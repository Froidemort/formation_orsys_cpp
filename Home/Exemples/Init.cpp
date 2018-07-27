// Fichier './Exemples/Init.cpp'
#include <iostream>
using namespace std ;

class B { public : B() { cout << "B cree\n" ;}
//          static int foo = 8 ;  // ne compile plus en C++/ISO !
            static int foo ; // ok mais initialisation obligatoire a faire
        } ;

class A { public : A() { cout << "A cree: B::foo = " << B::foo << '\n' ;}
        } ;

A a1 ;
int main( void) {

    A a2 ;
    cout << "On a cree un 2ieme A\n" ;

    B b ;
    cout << "B::foo vaut " << B::foo << endl ;
}

int B::foo = 9 ; // Syntaxe specifique aux champs statiques
                 // Mais l'initialisation est obligatoire
// Fin du fichier './Exemples/Init.cpp'
