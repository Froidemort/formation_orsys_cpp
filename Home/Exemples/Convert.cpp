#include <iostream>  // Fichier './Exemples/Convert.cpp'
using namespace std ;

double fon(
    int u,
    double f
) {
    cout << "u==" << u << "   -   " ;
    cout << "f==" << f << "   -   " ;
    return u*f ;
}

int main()
{
    double r1, r2, r3, r4 ;

    r1 = fon( 2, 3.3);   // appel normal
    cout << "fon( 2, 3.3)==" << r1 << endl ;

    r2 = fon( '\x02', 3.3); // correct '2' promu en int
    cout << "fon( '\\x02', 3.3)==" << r2 << endl ;

    r3 = fon( 2, 3); // correct 3 converti en double
    cout << "fon( 2, 3)==" << r3 << endl ;

    r4 = fon( 2.6, 3); // correct 2.6 converti en int
    cout << "fon( 2.6, 3)==" << r4 << endl ;

    return 0 ;
}   // Fin de './Exemples/Convert.cpp'
