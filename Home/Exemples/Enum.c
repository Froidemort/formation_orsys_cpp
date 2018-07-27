// Fichier './Exemples/Enum.c'
#include <stdio.h>         // C : printf peu typee

#include <iostream>        // C++ : '<<' plus type, mais promotion 
using namespace std ;      // C++

int main( void)
{
    enum Couleur { Blanc, Vert, Jaune, Rouge } ;
    enum         { NbPoints = 6000 } ;      // Equivaut a 'const'

    enum Couleur c1 = Rouge ;    // enum est facultatif en C++
//  enum Couleur c2 = 1 ;        // ERREUR en C++ (typage fort ici)
    Couleur c3 ;   // Impossible en C sans typedef. c3=? ici
    Couleur c4( Vert) ;          // Syntaxe du C++ uniquement

    // Mais le typage n'est pas si fort que cela...
    printf( "vert==>%d<\n", Vert) ;
    cout << "vert==>" << Vert << "<" << endl ;  // enum promu int
//  ++NbPoints ;             // ERREUR C/C++ NbPoints est 'const'
    cout << "NbPoints==>" << NbPoints << "<" << endl ;
    return 0 ;
}                                   // Fin de './Exemples/Enum.c'
