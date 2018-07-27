// Fichier './Exemples/Exception.cpp'
#include <iostream>

// Le namespace std contient deja une std::exception
// aussi on ne met pas "using namespace std ;"
using std::cout ; using std::cin  ; using std::endl ;

class exception {} ;      // Notre classe vide 'exception'
class e_saisie : exception {} ;
class e_nom_trop_long : e_saisie {} ;

int main( void) {

    int i ;

    cout << "Tapez 1, 2, 3, 4 ou ... " ;
    cin >> i ; cout << endl ;

    switch ( i ) {
        case 1 : throw i ;
        case 2 : throw "saisie de 2" ;
        case 3 : throw e_nom_trop_long() ;
        case 4 : { e_saisie X ; throw X ; }
        default : throw ;
    }
    cout << "Impossible d'etre ici" << endl ;
}           // Fin de './Exemples/Exception.cpp'
