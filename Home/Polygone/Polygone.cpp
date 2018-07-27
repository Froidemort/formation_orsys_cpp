// Fichier cree automatiquement par 'make'

#include <iostream>
#include "Polygone.h"
using namespace std ;


Polygone::Polygone( int nb) {

    NbCotes = nb ;
    TabLongueurs = new int [ NbCotes] ;
    for ( int i=0; i<NbCotes; i++)
        SetCote( i, 0) ;
}

Polygone::Polygone( const Polygone &p) {

//  cout << "(debug) constructeur de copie" << endl ;

    NbCotes = p.NbCotes ;
    TabLongueurs = new int [ NbCotes] ;
    for ( int i=0; i<NbCotes; i++)
        SetCote( i, p.TabLongueurs[ i]) ;
}


void Polygone::SetCote( int numero, int longueur) {
    if ( numero >= 0 && numero < NbCotes )
        TabLongueurs[ numero] = longueur ;
    else
        cerr << "debordement dans SetCote()" << endl ;
}

int Polygone::Perimetre( void) const {
    int somme = 0 ;
    for ( int i=0; i<NbCotes; i++)
        somme += TabLongueurs[ i] ;
    return somme ;
}

void Polygone::Affiche( void ) const {
    cout << "Polygone a " << NbCotes << " cotes:\t" ;
    for ( int i=0; i<NbCotes; i++)
        cout << " " << TabLongueurs[ i] ;
    cout << endl ;
}


int Polygone::Aire( void ) const {
    cerr << "Aire de polygone quelconque inconnue\n" ;
    return 0 ;
}

const Polygone& Polygone::operator=( const Polygone& p) {

//  cout << "(debug) appel de l'affectation" << endl ;

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


// Fin du fichier genere automatiquement
