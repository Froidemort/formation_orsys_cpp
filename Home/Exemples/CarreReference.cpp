// Fichier './Exemples/CarreReference.cpp'

#include <iostream>
using namespace std ;

void carre( const int &i) {
     int j = i ;
     j = j * j ;   // Aucun effet sur i
}

void carre2( int &i) {
     i = i*i ;                
}

int main( void) {
    int i=6, j=6 ;
    const int ci=6; const int cj=6;

    carre( i) ;    // Conversion implicite volatile-->const
    carre2( j) ;   // Seule facon de modifier la variable
    
    cout << "i=" << i << endl ;
    cout << "j=" << j << endl ;
    
    carre( ci) ;
//  carre2( cj) ;  // Erreur de compilation
    
    cout << "ci=" << ci << endl ;
    cout << "cj=" << cj << endl ;
    
    return 0 ;
}
// Fin de './Exemples/CarreReference.cpp'
