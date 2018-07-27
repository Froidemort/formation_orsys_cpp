// Fichier './Exemples/Polygone/Test-Carre.cpp'

#include "Carre.h"
using namespace std ;

int main( void) {

    Carre A ;
    Carre B( 5) ;
    Polygone C = B ;
    Rectangle D = B ;

    B.Affiche() ;
    (*(Polygone *)&B).Affiche() ;
    C.Affiche() ;
    D.Affiche() ;

    cout << "Aire de A: " << A.Aire() << endl ;
    cout << "Aire de B: " << B.Aire() << endl ;
    cout << "Aire de D: " << D.Aire() << endl ;

    Polygone *p = &D ; p->Affiche() ;
    cout << "Aire de *p: " << p->Aire() << endl ;

    Polygone *q = &B ; q->Affiche() ;
    cout << "Aire de *q: " << q->Aire() << endl ;

    cout << "Fin normale du programme" << endl ;
    return 0 ;
}

// Fin de './Exemples/Polygone/Test-Carre.cpp'
