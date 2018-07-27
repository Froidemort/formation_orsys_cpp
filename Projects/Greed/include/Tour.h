// Fichier './Tour/Tour.h'

#ifndef TOUR_H_INCLUDED
#define TOUR_H_INCLUDED

#include "../include/De.h"

const int Nb_Des = 5 ;

class Tour {                   // Un tour peut comporter plusieurs lancers de des

private:
    De des[ Nb_Des];
    int points_cumules ;
    int points_du_tour ;
    int calcul_score( void) const ;
    
public:
    Tour( void) {
        points_cumules = 0 ;
        points_du_tour=calcul_score();
    }

    void Affiche( void) const ;
    int nouveau_lancer( void) ;
    int score( void) const ; 
} ;


//---------------------------------------------------------------------------------
inline int Tour::score( void) const
{
    return points_du_tour ;
}

#endif

// Fin de './Tour/Tour.h'
