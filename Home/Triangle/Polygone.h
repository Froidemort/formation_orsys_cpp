// Fichier './Triangle/Polygone.h'
#ifndef POLYGONE_H_INCLUDED
#define POLYGONE_H_INCLUDED

class Polygone {    // Un Polygone est constitue de 0 a n cotes

    public :
        Polygone( void) { NbCotes = 0 ; TabLongueurs = NULL ; }
        Polygone( int nb) ;
        Polygone( const Polygone &p) ;

        virtual ~Polygone() { 
                if ( NbCotes ) delete [] TabLongueurs ; }

        void SetCote( int indice, int longueur) ;
        int GetCote( int indice) const;
        int GetNbCotes( void) const { return NbCotes; }
        void SetNbCotes( int nbcotes) { NbCotes = nbcotes; }
        virtual void Affiche( void) const ;

        const Polygone& operator=( const Polygone &p) ;

    protected :
        int *TabLongueurs ;    // les longueurs des cotes

	private :
        int NbCotes ;          // le nombre de cotes

} ;

#endif                         // Fin de './Triangle/Polygone.h'
