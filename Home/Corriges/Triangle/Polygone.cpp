// Fichier './Triangle/Polygone.cpp'

#include <iostream>
#include "Polygone.h"


Polygone::Polygone( int nb) {

    NbCotes = nb ;
    TabLongueurs = new int [ NbCotes] ;
    for ( int i=0; i<NbCotes; i++)
        SetCote( i, 0) ;
}


Polygone::Polygone( const Polygone &p) {

//  cout << "(debug) constructeur de copie" << std::endl ;

    NbCotes = p.NbCotes ;
    TabLongueurs = new int [ NbCotes] ;
    for ( int i=0; i<NbCotes; i++)
        SetCote( i, p.TabLongueurs[ i]) ;
}


void Polygone::SetCote( int numero, int longueur) {
    if ( numero >= 0 && numero < NbCotes )
        TabLongueurs[ numero] = longueur ;
    else
        std::cerr << "debordement dans SetCote()" << std::endl ;
}


void Polygone::Affiche( void ) const {
    std::cout << "Polygone a " << GetNbCotes() << " cotes:\t" ;
    for ( int i=0; i<GetNbCotes(); i++)
        std::cout << " " << TabLongueurs[ i] ;
    std::cout << std::endl ;
}


Polygone &Polygone::operator = ( const Polygone &p) {

    std::cerr << "(debug) affectation d'un polygone a un polygone" << std::endl ;

    if ( this != &p ) {

        int *tmp = new int [ p.NbCotes] ;
        if ( NbCotes) delete [] TabLongueurs ;
        TabLongueurs = tmp ;
        NbCotes = p.NbCotes ;
        for ( int i=0; i<NbCotes; i++)
            SetCote( i, p.TabLongueurs[ i]) ;
    }
    return *this ;
}

// Fin de './Triangle/Polygone.cpp'
