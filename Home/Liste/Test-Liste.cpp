/*
 * Test-Liste.cpp (Denis Gillain - Version 1.2)
 */

#include "Rand/Rand.h" // Specifier ou trouver les include a la compilation
#include "De/De.h"     // par exemple dans le 'Makefile'
#include "Liste.h"     // Travail demande: Ecrire ce fichier et lui seul

// Soit XXX une classe quelconque d'objets:
// Ce programme realise une liste de XXX par un heritage multiple entre XXX et Element
// A titre de test, on choisit un De pour XXX

#include <iostream>    // pour std::cout

int main( void) {

    class ElementDe : public Element, public De {} ;
    ElementDe *des = (ElementDe *)0;  // Tete de liste

    des = new ElementDe ;
    des->ajoute( new ElementDe) ;
    des->ajoute( new ElementDe) ;
    des->ajoute( new ElementDe) ;


//  for ( premier de liste ; tant qu'il y en a ; on passe au suivant)
    for ( ElementDe *p=des; p; p=(ElementDe *)p->suivant())
        std::cout << p << " (de) a pour face: " << p->valeur() << '\n' ;

//  affiche 2 fois la meme liste (pour voir si les des ont change)
    for ( ElementDe *p=des; p; p=(ElementDe *)p->suivant())
        std::cout << p << " (de) a pour face: " << p->valeur() << '\n' ;

    for ( ElementDe *d, *p=des; p; ) {
        d=p ; p=(ElementDe *)p->suivant() ; delete d ;
    }

    return 0 ;
}

// Fin de Test-Liste.cpp
