// Fichier './Exemples/Stack.cpp'
#include <iostream>
#include "Stack.h"
using namespace std ;
int main( void) {

    Stack pile ;

    pile.push( 1) ;
    pile.push( 2) ;
    pile.push( 3) ;

    cout <<"capacite de la pile: "<< pile.capacite << endl ;
    for ( int i=0;i<6;i++) try {  // Arbitraire pour voir

          cout <<"dans la pile... "<< pile.pop() << endl ;
       } catch ( runtime_error &e) {

          cout << e.what() << endl ; // retourne dans for
       } catch ( ... ) {

          cerr << "Alors la !\n" ;
    }

    cout << "Sortie normale" << endl ; return 0;
}                          // Fin de './Exemples/Stack.cpp'
