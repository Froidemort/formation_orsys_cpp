// Fichier './Exemples/Portee.c'
// compiler 'g++ -Wall -v -x c++ Portee.c'
//          -v pour avoir les passes de compilation
//          -x c++ : compile explicitement du C++


#include <iostream>
using namespace std ;

int i = 1;                                              //-1-//
extern int j ;                                          //-2-//

namespace entete { int j=i, i=2, n=i; }                 //-3-//

static int k = 3 ;                                      //-4-//

static void f( void) {                                  //-4-//

    int i = 4 ;
    cout << "dans f(): i=" << i << endl ;
    cout << "dans f(): ::i=" << ::i << endl ;           //-5-//
    cout << "dans f(): entete::i=" << entete::i << endl ;
}

int main( void) {

    f() ;

    cout << "dans main(): i=" << i << endl ;
    int i = 5 ;                                         //-6-//

    for ( int i=13; i<14; i++)                          //-7-//
        cout << "dans for(;;): i=" << i << endl ;

    cout << "dans main(): i=" << i << endl ;
    cout << "dans main(): k=" << k << endl ;
//  cout << "dans main(): j=" << j << endl ;  // Erreur de LINK (ld)

    cout << " ... et j=" << entete::j << " n=" << entete::n << endl ;

    return 0 ;
}                          // Fin de './Exemples/Portee.c'
