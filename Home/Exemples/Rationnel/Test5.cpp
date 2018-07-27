// Fichier './Exemples/Rationnel/Test5.cpp'
#define TEST5

#include <iostream>
#include "Rationnel.h"
#include "Cout.h"
using namespace std ;

int main( void)
{
    Rationnel A( 14, 5); double x=A ;

    cout << "A=" << A << endl ;
    cout << "x=" << x << " et i=" << int( A) << " notation C++" << endl ;
    cout << "(int)A=" << (int)A << " notation du C" << endl ;
    return 0;
}
// Fin de './Exemples/Rationnel/Test5.cpp'
