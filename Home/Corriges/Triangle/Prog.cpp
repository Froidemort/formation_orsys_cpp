// Fichier './Triangle/Prog.cpp'
// Fichier './Corriges/Triangle/Prog.cpp' (lien physique)

#include <iostream>
#include "Triangle.h"

// On peut decommenter les TESTx pour activer un test
//#define    TEST1
//#define    TEST2
//#define    TEST3
//#define    TEST4
//#define    TEST5
//#define    TEST6
//#define    TEST7
//#define    TEST8
//#define    TEST9

int main( void) {

    Triangle A( 3, 3, 3);  A.Affiche();
    Triangle B( 10, 1, 1); B.Affiche(); // triangle erronee

#ifdef TEST1
    std::cout << "--------------------- Test 1\n" ;
    Triangle C( std::cin);    C.Affiche();
    C = A ;                   C.Affiche();
#endif

#ifdef TEST2
    std::cout << "--------------------- Test 2\n" ;
    Triangle D( 1);           D.Affiche();
#endif

#ifdef TEST3
    std::cout << "--------------------- Test 3\n" ;
    Polygone E( 3); E.SetCote( 0, 3); E.SetCote( 1, 4); E.SetCote( 2, 5);
//    A = E ;                                   // Ne compile pas !
    A = *((Triangle *)&E) ;   A.Affiche();    // A vos risques et perils
    Polygone &s = B ; s = E ; B.Affiche();    // A vos risques et perils
    Triangle F ; F = E ;      F.Affiche();    // Seule 'bonne' technique
#endif

#ifdef TEST4
    std::cout << "--------------------- Test 4\n" ;
    // G est un triangle (c'est une copie de A legerement modifiee)
    Polygone G( A) ;   G.SetCote( 0, 4) ;
                       G.Affiche() ;
                       A.Affiche() ;
#endif

#ifdef TEST5
    Polygone H( A) ;   H.SetCote( 0, 4) ;
    std::cout << "--------------------- Test 5\n" ;
    Polygone *p = &A ; p->Affiche() ;   // Doit etre methode du triangle
              p = &H ; p->Affiche() ;   // Doit etre methode du polygone
#endif

#ifdef TEST6
    Polygone I( A) ;   I.SetCote( 0, 4) ;
    std::cout << "--------------------- Test 6\n" ;
    Polygone &r = A ;  r.Affiche() ;   // Affectation de reference
              r = I ;  r.Affiche() ;   // Affectation d'objet
    // '=' a 2 sens : initialiser la reference ou affecter l'objet
#endif

#ifdef TEST7
    std::cout << "--------------------- Test 7\n" ;
    A.SetCote( 0, 1000) ; A.Affiche(); // Triangle impossible 
#endif

#ifdef TEST8
    std::cout << "--------------------- Test 8\n" ;
    A.SetCote( 10, 10) ; A.Affiche(); // Erreur a l'execution
#endif

#ifdef TEST9
    // Pour ce test, mettez en commentaire le constructeur de copie
    // dans Polygone.h et Polygone.cpp
    std::cout << "--------------------- Test 9\n" ;
    { Triangle J( A) ; A.Affiche() ; } 
    A.Affiche() ;    // Puis expliquez pourquoi le programme plante 
#endif

    return 0 ;
}

// Fin de './Triangle/Prog.cpp'
