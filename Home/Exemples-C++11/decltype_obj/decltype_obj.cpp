// Fichier './Home/Exemples-C++11/decltype_obj/decltype_obj.cpp'
#include <iostream>
#include <array>  // nouveau conteneur disponible uniquement depuis C++11
typedef std::string Joueur ;
typedef std::array< Joueur, 15> Quinze ;

int main( void) {  // ------------------------------------------------ 73

    // Teste la norme de compilation du GCC (pas la version du GCC)
    #if __cplusplus==201402L
      std::cout << "Compile en C++14 - " << __cplusplus << std::endl ;
    #elif __cplusplus==201103L
      std::cout << "Compile en C++11 - " << __cplusplus << std::endl ;
    #else
      std::cout << "Compile .......... " << __cplusplus << std::endl ;
    #endif

    Quinze France, Italie, Ecosse ;      // Appels au constructeur 'vide'

    decltype( France) x ;   // Definition d'une variable de type 'Quinze'
    typedef decltype( France) Equipe ;     // Definition du type 'Equipe'
    Equipe& MonEquipe = France ; Equipe const* pMyTeam = &Ecosse ;
    std::cout << pMyTeam->size() << " joueurs dans l'equipe d'Ecosse\n" ;
    std::cout << MonEquipe.size() << " joueurs aussi pour la France\n" ;
    return 0 ;
}   // fin de fichier
