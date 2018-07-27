// Fichier './Exemples/New.cpp'

#include <iostream> 
#include <stdlib.h>

using namespace std ;

int main(
     void
) {

     // Provoque un probleme
     long long *pi = new long long[ (unsigned int )-1];

     // Et reprend l'execution
     cout << "Mais on a quand meme essaye" << endl ;

     delete [] pi ;
}    // Fin de './Exemples/New.cpp'
