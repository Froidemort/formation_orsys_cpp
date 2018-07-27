// Fichier './Exemples/Array.cpp'

#include <iostream>
#include "Array.h"
using namespace std ;

void f( const int& x) {
    return ;
}

int main( void) {

    Array A ;
    int i ;
    long somme = 0L ;

    for ( i=0; i<A.capacite; i++) {
        A[ i] = i ;                    // 'non-const'
        somme += A[ i] ;               // 'non-const'
        f( A[ i]) ;                    // 'non-const'
    }

    cout << "A[ 12]    == " << A[ 12]    << endl ;  // 'non-const'
    cout << "A.at( 12) == " << A.at( 12) << endl ;  // 'const'
    return 0;
}                       // Fin du './Exemples/Array.cpp'
