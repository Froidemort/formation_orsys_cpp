// Fichier './Exemples/CarrePointeur.cpp'

#include <iostream>
using namespace std ;

void carre( int *pi) {         //     surcharge :
     (*pi) = (*pi)*(*pi) ;     // 2 fonctions peuvent 
}                              // avoir meme nom, pourvu
                               // qu'elles different par
void carre( int i) {           // le nombre et les types
     i = i*i ;                 // des arguments.
}                              //     surcharge :
int main( void) {              // Ne compile pas en C !
    int i=6, j=6 ;

    carre( i) ;
    carre( &j) ;
    
    cout << "i=" << i << endl ;
    cout << "j=" << j << endl ;
    
    return 0 ;
}
// Fin de './Exemples/CarrePointeur.cpp'
