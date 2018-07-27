// Fichier './Exemples/Rationnel/Test6.cpp'
#define TEST5 // SIC -DG-

#include <iostream>
#include "Rationnel.h"
#include "Cout.h"
using namespace std ;

int main( void)
{
    Rationnel A( 4, 5);
    Rationnel B( 4, 3);

    cout << "A=" << A++ << endl ;
    cout << "A=" << A << " apres A++" << endl ;
    cout << "B=" << B << endl ;
    cout << "B=" << ++++B << " apres ++++B" << endl ;
    return 0;
}
// Fin de './Exemples/Rationnel/Test6.cpp'
