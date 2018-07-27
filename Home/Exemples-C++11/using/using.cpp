// debut de ./Exemples-C++11/using/using.cpp
#include <iostream>
using namespace std ; // Syntaxe obsolete - deconseillee, trop laxiste
// using std::cout ;  // Preferable - moins d'effets de bord

struct A {
} ;

int main() { // ----------------------------------------------------70

    A a1 ;              // A::A()     --> constructeur vide/par defaut
    A a2( 12) ;         // A::A( int) --> constructeur a un entier

    cout << "\nfin du programme\n" ;
    return 0 ;
}
// fin de fichier
