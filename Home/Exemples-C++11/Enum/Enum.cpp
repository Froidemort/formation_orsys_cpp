// Fichier './Home/Exemples-C++11/Enum/Enum.cpp'
#include <iostream>
using std::cout ;

int main( void) {  // --------------------------------------------- 70
    enum Couleur { blanc, jaune, vert } d( blanc) ;
    enum Sens { droite, gauche } e( Sens::droite) ;  // ou e( droite)
    if ( d < gauche ) cout << "Anomalie qui compile avec warning\n";
    if ( d < 3 ) cout << "Une autre, compile sans warning en GCC\n";
    if ( d >= e) cout << "Et encore, compile avec warning en GCC\n";
    Couleur a ;             // Combien vaut a ici ?
}   // fin de fichier
