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

//  std::cerr << "(debug) constructeur de copie de Polygone" << std::endl ;

    NbCotes = p.NbCotes ;
    TabLongueurs = new int [ NbCotes] ;
    for ( int i=0; i<NbCotes; i++)
        SetCote( i, p.TabLongueurs[ i]) ;
}


void Polygone::SetCote( int numero, int longueur) {
    std::cout << "Numero : " << numero << ", longueur : " << longueur << "\n";
    if ( numero >= 0 && numero < NbCotes ){
        std::cout << " Avant " << TabLongueurs[ numero] << " " << longueur << "\n"; 
        TabLongueurs[ numero] = longueur ;
        std::cout << " Apres " << TabLongueurs[ numero] << " " << longueur << "\n";  
        }       
    else {
        std::cerr << "debordement dans SetCote()" << std::endl ;
    }
}

int Polygone::GetCote( int numero) const {
    if ( numero >= 0 && numero < NbCotes ){
        return TabLongueurs[ numero];
    }
    else
        std::cerr << "debordement dans GetCote()" << std::endl ;
}


void Polygone::Affiche( void ) const {
    std::cout << "Polygone a " << GetNbCotes() << " cotes:\t" ;
    for ( int i=0; i<GetNbCotes(); i++)
        std::cout << " " << TabLongueurs[ i] ;
    std::cout << std::endl ;
}


const Polygone& Polygone::operator=( const Polygone &p) {

//  std::cerr << "(debug) affectation de Polygone" << std::endl ;

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
