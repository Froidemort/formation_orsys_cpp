// Fichier './Exemples/DivZero.cpp'
//
// compiler: 'g++ -Wno-div-by-zero -Wall DivZero.cpp'
//           -Wno-div-by-zero desactive le Warning

#include <iostream>
using namespace std ;

int main(
     void
) {

     try {  // Provoque un probleme
        int i = 16 / 0 ;
     } catch ( ... ) {
        cout << "gestionnaire d'exceptions" << endl ;
     }

     // Et reprend l'execution... peut etre
     cout << "Mais on a quand meme essaye" << endl ;
     return 0 ;
}    // Fin de './Exemples/DivZero.cpp'
