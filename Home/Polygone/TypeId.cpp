// Fichier './Exemples/Polygone/TypeId.cpp'
#include <typeinfo>   // pour 'type_info' et 'typeid()'
#include <iostream>   // pour 'cout' et 'endl'
#include "Carre.h"
#include "Triangle.h"
using namespace std ;
int main( void) {

    Polygone *C[ 4] ; int i ;
    C[ 0] = new Triangle( 6, 7, 8) ;
    C[ 1] = new Rectangle( 10, 11) ;
    C[ 2] = new Polygone( 6) ;
    C[ 3] = new Carre( 2) ;

    for ( i=0; i<4; i++ ) {
        if ( typeid( *C[ i]) == typeid( Carre) )
             cout << " ... Le carre d'as !" << endl ;
        cout << typeid( *C[ i]).name() << endl ;
    }

    cout << "entier: >" << typeid( i).name() << "<\n" ;
    return 0 ;
}            // Fin de './Exemples/Polygone/TypeId.cpp'
