// Fichier './Exemples/Rationnel/Test2.cpp'

#include <iostream>
#include "Rationnel.h"
using namespace std ;

int main( void)
{
    Rationnel A( 4, 5);
    Rationnel B( 3, 4);

    cout << "A="; A.Affiche(); cout << endl ;
    cout << "B="; B.Affiche(); cout << endl ;

    A.ajoute( B) ;
    cout << "A="; A.Affiche(); cout << " apres" << endl ;

    B.ajoute( Rationnel( 1, 5)).ajoute( Rationnel( 58, 94)) ;
    cout << "B="; B.Affiche(); cout << " apres" << endl ;

    return 0;
}   // Fin de './Exemples/Rationnel/Test2.cpp'
