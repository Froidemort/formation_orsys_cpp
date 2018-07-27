// Fichier './Exemples/Array.h'
#include <stdexcept>
#include <iostream>
using namespace std ;
const unsigned int array_size = 100 ;

class Array {
  public:
    int& operator[]( size_t) ;
    const int& operator[]( size_t) const ;
    int at( size_t i) const { return (*this)[ i] ; } // mentionne 'const' []

    enum { capacite = array_size } ;                 // simule un 'const'
  private:
    int data[ array_size];
} ; 

inline int& Array::operator[] (
    size_t indice
) {
    if ( indice >= array_size || indice < 0 )
        throw range_error( "Indice en dehors du tableau") ;
    return data[ indice] ;
}

inline const int& Array::operator[] (                // 'const' ici
    size_t indice
) const {                                            // 'const' la
    std::cerr << "version 'const'" << std::endl ;    // DEBUG ici
    if ( indice >= array_size || indice < 0 )
        throw range_error( "Indice en dehors du tableau") ;
    return data[ indice] ;
}                            // Fin de './Exemples/Array.h'
