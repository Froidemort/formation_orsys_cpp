// Fichier './Corriges/Tour/Tour.cpp'

#include <iostream>
#include "Tour.h"



//---------------------------------------------------------------
void Tour::Affiche( void) const
{
    //std::cout << "Des:" ;
    std::cout << "    " ;
    for (int i = 0; i<Nb_Des; i++)
        std::cout << ' ' << des[ i].valeur() ;
    std::cout << "   score: " << points_du_tour << std::endl ;
}



//-------------------------------------------------------------------
int Tour::nouveau_lancer(
    void
) {
    int i, j, k, nb ;

    // On ne peut pas faire un nouveau_lancer() si les des n'ont pas gagne
    // au prealable (il faut avoir fait un lancer)
    if ( points_du_tour == 0 )
        return 0 ;

    // Recopie les des dans un tableau, pour les flaguer
    int tab[ Nb_Des];
    for ( i = 0; i < Nb_Des; i++)
        tab[i] = des[ i].valeur();
    
    // Je mets tab[i] = 0 si le De i ne doit pas etre rejoue
    // d'abord je cherche les triplets:
    for ( i=1; i<=6; i++)    {

        nb = 0 ;
        for ( j=0; j<Nb_Des; j++) {

            if (tab[ j] == i) nb++;
            else {}

            if ( nb == 3 ) {

                for ( k=0; k<=j; k++)
                    if ( tab[ k]== i )
                        tab[ k] = 0 ;
                    else {}
                break ;        // on a un triplet : on peut arreter 
            }
        }

        if ( nb == 3 )
            break ;
        else {}
    }

    // Je flague les faces marquees 1 et 5
    for ( j = 0; j < Nb_Des; j++)
        if (tab[j] == 1 || tab[j] == 5)
            tab[j] = 0;
        else {}

    // Par defaut tous les des peuvent etre rejoues
    bool tous = true;
    for ( j=0; j < Nb_Des; j++)
        if (tab[j] != 0) {
            des[ j].lance();
            tous = false;
        }

    if ( tous ) {
    
        for ( j=0; j<Nb_Des; j++)
            des[ j].lance() ;

        points_cumules = points_du_tour ;
    }

    int nouveau_score = calcul_score() ;

    if ( tous )
        if ( nouveau_score == 0 ) {
            points_cumules = 0 ;                // Tout perdu
            points_du_tour = 0 ;                // Tout perdu
        } else
            points_du_tour = points_cumules + nouveau_score ;

    else
        if ( nouveau_score <= points_du_tour - points_cumules ) {
            points_cumules = 0 ;                // Tout perdu
            points_du_tour = 0 ;                // Tout perdu
        } else
            points_du_tour = points_cumules + nouveau_score ;

    return points_du_tour ;
}



//==================================================================
int Tour::calcul_score(
    void
) const {
    int i, nb, pts = 0;

    for (i = 0, nb = 0; i < Nb_Des; i++)       // Nb de faces '1'
        if (des[i].valeur() == 1) nb++;
    if      (nb == 5) pts = 1200;
    else if (nb == 4) pts = 1100;
    else if (nb == 3) pts = 1000;
    else if (nb == 2) pts =  200;
    else if (nb == 1) pts =  100;
    else {}


    for (i = 0, nb = 0; i < Nb_Des; i++)       // Nb de faces '5'
        if (des[i].valeur() == 5) nb++;
    if      (nb == 5) pts  = 600;
    else if (nb == 4) pts += 550;
    else if (nb == 3) pts += 500;
    else if (nb == 2) pts += 100;
    else if (nb == 1) pts +=  50;
    else {}

    for (i = 0, nb = 0; i < Nb_Des; i++)       // Triple de '2'
        if (des[i].valeur() == 2) nb++ ;
    if ( nb >= 3 ) pts += 200 ;
    else {}
        
    for (i = 0, nb = 0; i < Nb_Des; i++)       // Triple de '3'
        if (des[i].valeur() == 3) nb++ ;
    if ( nb >= 3 ) pts += 300 ;
    else {}
    
    for (i = 0, nb = 0; i < Nb_Des; i++)       // Triple de '4'
        if (des[i].valeur() == 4) nb++ ;
    if ( nb >= 3 ) pts += 400 ;
    else {}
    
    for (i = 0, nb = 0; i < Nb_Des; i++)       // Triple de '6'
        if (des[i].valeur() == 6) nb++ ;
    if ( nb >= 3 ) pts += 600 ;
    else {}

    return pts;
}

// Fin de './Corriges/Tour/Tour.cpp'
