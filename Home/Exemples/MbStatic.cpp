// Fichier './Exemples/MbStatic.cpp'

#include <iostream>
using namespace std ;

#include "MbStatic.h"

int main( void)
{   // Il est essentiel de connaitre la norme employee
    cout << "Norme utilisee: " << __cplusplus << endl ;

    cout << "Actuellement " << Rationnel::NbRationnels() ;
        cout << " rationnels(s) dans le programme" << endl ;

    Rationnel a(3,4), b(4,5), p[ 4], *q ;
    cout << Rationnel::NbRationnels() << " crees" << endl ;

    q = new Rationnel ;
         cout << "On en alloue un: il y en a " ;
         cout << Rationnel::NbRationnels() << endl ;
    delete q ;
         cout << "On le detruit:  il en reste " ;
         cout << Rationnel::NbRationnels() << endl ;
    return 0 ;
}

// Initialisation du champ statique: ce n'est pas une instruction:
unsigned int Rationnel::_nb = 0 ;
// Une instruction ne pourrait pas modifier le champ 'private'
// Une instruction est obligatoirement entre {}
// Ce n'est pas une affectation, mais une initialisation!
// Fin de './Exemples/MbStatic.cpp'
