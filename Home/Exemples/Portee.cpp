// Fichier './Exemples/Portee.cpp'

#include <iostream>
using namespace std ;

static int X( 8) ;

int main( void) {

    int X( 3) ;

    cout << "X local ... " << X << endl ;
    cout << "X statique ... " << ::X << endl ;

    return 0 ;
}   // Fin de './Exemples/Portee.cpp'
