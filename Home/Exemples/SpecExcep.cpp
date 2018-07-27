// Fichier './Exemples/SpecExcep.cpp'

#include <iostream>
using namespace std ;

void f( int i) {
    if ( i >=0 && i <=9 ) return ;
    if ( i < 0 ) throw "positif svp" ; 
    throw i ;
}


void MaFonction( void) {
    cerr << "(MaFonction) et maintenant a quoi ca sert?" << endl ;
}


int main( void) { int i ;

    set_unexpected( MaFonction) ;

    // Rien n'est prevu pour sortir de cette boucle
    while ( true ) 
        try {
            cout << "Tapez un chiffre positif ... " ;
            cin >> i ;
            f( i) ;
        } catch( int i) {
            cerr << "(catch int) Un chiffre, pas plus! (" << i << ")\n" ;
        } catch ( ... ) {
            cerr << "(catch banalise) Alors la ! (76155127)\n" ;
        }

    cout << "Impossible et pourtant on est ici (97412833)" << endl ;
    return 1 ;
}   // Fin de './Exemples/SpecExcep.cpp'
