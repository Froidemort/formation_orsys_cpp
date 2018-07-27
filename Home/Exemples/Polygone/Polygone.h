// Fichier './Exemples/Polygone/Polygone.h'
#ifndef POLYGONE_H_INCLUDED
#define POLYGONE_H_INCLUDED

class Polygone {    // Un Polygone est constitue de 0 a n cotes
        int NbCotes ;          // le nombre de cotes
    protected :
        int *TabLongueurs ;    // les longueurs des cotes
    public :
        Polygone( void) { NbCotes = 0 ; TabLongueurs = NULL ; }
        Polygone( int nb) ;
        Polygone( const Polygone &p) ;                   // cf
        virtual ~Polygone() { // toujours dans une classe de base
                if ( NbCotes ) delete [] TabLongueurs ; }
        void SetCote( int indice, int longueur) ;
        int Perimetre( void) const ;
        virtual int Aire( void) const ;
        virtual void Affiche( void) const ;

        const Polygone& operator=( const Polygone& p) ;  // cf

} ;
#endif                // Fin de './Exemples/Polygone/Polygone.h'
