// Fichier './Exemples/Rationnel/Test3.cpp'

#include <iostream>
#include "Rationnel.h"
using namespace std ;

int main( void)
{
    Rationnel A( 4, 5);
    Rationnel B( 3, 4);

    cout << "A="; A.Affiche(); cout << endl ;
    cout << "B="; B.Affiche(); cout << endl ;

    A += B ;
    cout << "A="; A.Affiche(); cout << " apres" << endl ;

    B += Rationnel( 1, 5) += Rationnel( 58, 94) ;
    cout << "B="; B.Affiche(); cout << " apres" << endl ;

    return 0;
}   // Fin de './Exemples/Rationnel/Test3.cpp'
