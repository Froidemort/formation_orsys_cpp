// debut de ./Exemples-C++11/is_constructible/is_constructible.cpp
#define IS_CONSTRUCTABLE_CPP_FILE
// #define AVEC_CTOR_MOVE // Sans CTOR_MOVE --> utilise le ctor de copie
#define AVEC_CTOR_MOVE_DELETE  // La classe n'est plus move_constructible
#include "../NewCtor/NewCtor.cpp"


int main( void) {  // ------------------------------------------------ 73

    std::cout
       << "\n T is ...\n" << std::boolalpha
       << "\tConstructible from const T&? "
       << std::is_constructible< T, T const&>::value << '\n'
       << "\tTrivially-constructible from const T&? "
       << std::is_trivially_constructible< T, T const&>::value << '\n'
       << "\tTrivially-constructible from int? "
       << std::is_trivially_constructible< T, int>::value << '\n'
       << "\tConstructible from int? "
       << std::is_constructible< T, int>::value << '\n'
       << "\tConstructible from char const*? "
       << std::is_constructible< T, char const*>::value << '\n'
       << "\tNothrow-constructible from char const*? "
       << std::is_nothrow_constructible< T, char const*>::value << '\n'
       << "\tMove_constructible from const T&? "
       << std::is_move_constructible< T>::value << '\n'
       << "\tTrivially-move_constructible from const T&? "
       << std::is_trivially_move_constructible< T>::value << '\n'
       << '\n'
    ;

}   // fin de fichier
