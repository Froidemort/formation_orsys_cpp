// Fichier './Exemples/Template.cpp'
#include <iostream>
using namespace std ;

template< class T>          // 'class' est un mot reserve
inline void carre( T &x) {  // on peut aussi mettre 'typename'
    x = x * x ;
}

int main( ) {
    int i = 4 ;
    double pi = 3.14 ;   // ou Rationnel R( 5, 3) ; ...
    char s[ 6] = "hum" ;

    carre ( i); carre ( pi);

    cout << " i = " << i  << endl ;
    cout << "pi = " << pi << endl ;

//  carre( s) ;  // Ne compile pas:
//  In function 'void carre(T&) [with T = char [6]]':
//  invalid operands of types 'char [6]' to binary 'operator*'
    return 0 ;
}               // Fin de './Exemples/Template.cpp'
