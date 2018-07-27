// Fichier './Exemples/VeriChiffre.cpp'

#include <iostream>
using namespace std ;

void f( int i){
    if ( i >0 && i <=9 ) return ;
    if ( i <= 0 ) throw "positif svp" ; 
    throw i ;
}

int main( void) { int i ;

    while ( true )         // Boucle infinie
        try {
            cout << "Tapez un chiffre positif ... " ;
            cin >> i ;     // Delicat le 'cin', memes defauts que scanf()
            f( i) ;
        } catch( int i) {
            cerr << "(catch int) Un chiffre, pas plus! (" << i << ")\n" ;
        } catch ( ... ) {
            cerr << "(catch banalise) Alors la ! (76155127)\n" ;
        }

    cout << "Impossible d'etre ici (97412833)" << endl ;
    return 1 ;
}   // Fin de './Exemples/VeriChiffre.cpp'
