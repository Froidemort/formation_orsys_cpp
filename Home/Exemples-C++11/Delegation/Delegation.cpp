// Fichier './Home/Exemples-C++11/Delegation/Delegation.cpp'
#include <iostream>

#if ( __cplusplus!=201402L && __cplusplus!=201103L )
    // 'noexcept' est un mot clef c++11 remplacant throw()
    #define noexcept throw()
#endif

class MaClasse {      // --------------------------------------------- 73
  public:
    MaClasse( int nb) noexcept : _nb( nb) {    // ctor fonctionnel
        std::cout << "constructeur fonctionnel\n"; }
//    MaClasse( void) noexcept : _nb( 0) {}     // C++98, C++03, C++11...
    MaClasse( void) noexcept : MaClasse( 0) {   // C++11 uniquement
        std::cout << "   ...   appele par le constructeur vide\n"; }
  private:
        int _nb ;
} ;

int main( void) {      // -------------------------------------------- 73
    MaClasse a ;       // Appel au constructeur vide
    MaClasse b() ;     // N'a pas de sens: aucun warning, aucune action

    // Teste la norme de compilation du GCC
    #if __cplusplus==201402L
        std::cout << "Compilation en C++14 - " << __cplusplus << '\n';
    #elif __cplusplus==201103L
        std::cout << "Compilation en C++11 - " << __cplusplus << '\n';
    #else
        std::cout << "Compilation en C++ - "   << __cplusplus << '\n';
    #endif

}   // fin de fichier
