// Fichier './Exemples/Rationnel/Test4.cpp'

#include <iostream>
#include "Rationnel.h"
#include "Cout.h"
using namespace std ;

int main( void)
{
    Rationnel A( 4, 5);
    Rationnel B( 3, 4);

    cout << "A=" << A << endl ;
    cout << "B=" << B << endl ;

    A += B ;
    cout << "A=" << A << " (apres)" << endl ;

    B += Rationnel( 1, 5) += Rationnel( 58, 94) ;
    cout << "B=" << B << " (apres)" << endl ;

    return 0;
}

// Fin de './Exemples/Rationnel/Test4.cpp'
