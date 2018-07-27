// Fichier './Exemples/ReturnRef.cpp'

#include <iostream>
using namespace std ;

int &e(
    int tab[], int indice
) {
    return tab[ indice] ;
}


int main( void ) {
    int tab[ 100] ;
    for ( int i=0; i < 100; i++) {
        e( tab, i) = i ;
        cout << "tab[ " << i << "]= " << tab[ i] << endl ;
    }
}                     // Fin de './Exemples/ReturnRef.cpp'
