// Fichier './Corriges/Tour/Tour.h'

#ifndef TOUR_H_INCLUDED
#define TOUR_H_INCLUDED

#include "../De/De.h"

const int Nb_Des = 5 ;

class Tour {                   // Un tour peut comporter plusieurs lancers de des

private:
    De des[ Nb_Des];
    int points_cumules ;
    int points_du_tour ;

    int calcul_score( void) const ;    // calcule le score du lancer
    
public:
    Tour( void) {
        points_cumules = 0 ;   // Points comptabilises quand 5 des gagnent
        points_du_tour=calcul_score(); // Points apres avoir relance les des
                                       // par nouveau_lancer()
    }

    void Affiche( void) const ;// Affiche l'etat des des, le score actuel du lancer
    int nouveau_lancer( void) ;// Retourne 0 si le Tour est perdant, le score sinon
    int score( void) const ;   // Retourne le score, pour le premier lancer surtout
} ;


//---------------------------------------------------------------------------------
inline int Tour::score( void) const
{
    return points_du_tour ;
}

#endif

// Fin de './Corriges/Tour/Tour.h'
