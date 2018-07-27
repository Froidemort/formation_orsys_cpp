// Fichier './Exemples/Rationnel/Test1.cpp'

#include "Rationnel.h"

int main( void)
{
    Rationnel A;
    Rationnel B( 3, 4);
    Rationnel C( 2);
    Rationnel D = 2;
    Rationnel E( B);
    Rationnel F = C;

    A=C; 
    B=5;

    return 0;
}   // Fin de './Exemples/Rationnel/Test1.cpp'
