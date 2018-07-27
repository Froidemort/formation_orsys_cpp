// Fichier './Home/Exemples-C++11/nullptr/nullptr.cpp'
#include <iostream>     // std::cout std::nullprt_t
#include <cstdio>       // std::printf() NULL

#if ( __cplusplus!=201402L && __cplusplus!=201103L )
    // 'noexcept' est un mot clef c++11 remplacant throw()
    #define noexcept throw()
#endif

void f( long int) noexcept { std::cout << "f( long int) est appelee\n" ;}
void f( int*) noexcept { std::cout << "f( int*) est appelee\n" ;}

int main( void) {  // ------------------------------------------------ 73

    std::cout << "test sur Core i7 - stretch 64 bit - GCC "
              << __VERSION__ << " (norme " << __cplusplus << ")\n\n" ;

    std::cout << "sizeof (long)  == " << sizeof (unsigned long) << "\n" ;
    std::cout << "sizeof (int)   == " << sizeof (int) << "\n" ;
    std::cout << "sizeof (int*)  == " << sizeof (int*) << "\n" ;
    std::cout << "sizeof NULL    == " << sizeof NULL << "\n" ;
    std::cout << "sizeof nullptr == " << sizeof nullptr << "\n" ;
    std::cout << "pointeur NULL: " << NULL << "\n" ;
    std::printf( "pointeur NULL: %p\n\n", NULL) ;

    int i=123 ; f( i) ;    // Conversion implicite de int ---> long int
    f( NULL) ;             // NULL est probablement specifie long int
    f( nullptr);           // Mot-clef du C++11, meilleur choix

    std::nullptr_t x ;     // x est nullptr sous un autre nom
    f( x);
    if ( x == nullptr ) {
        std::cout << "On a bien 2 pointeurs NULL identiques\n" ;
    }
    return 0 ;
}   // fin de fichier
