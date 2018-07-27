// Fichier './Home/Exemples-C++11/Limites/Limites.cpp'
#include <iostream>    // cout, cerr, endl, std::boolalpha
using std::cout; using std::cerr; using std::endl ;

#include <cstdio>    // std::gets()
#include <limits>    // std::numeric_limits


int main( void) {  // ------------------------------------------------ 73

  cout << "Compilateur " << __VERSION__ << endl ;

  cout << "sizeof (unsigned int): " << sizeof (unsigned int) ;
  cout << " : de " << std::numeric_limits< unsigned int>::min() ;
  cout << " a " << std::numeric_limits< unsigned int>::max() ;
  cout << endl << endl ;

  cout << "sizeof    (size_t)   : " << sizeof (size_t) ;
  cout << " : de " << std::numeric_limits< size_t>::min() << " a " ;
  cout << std::numeric_limits< size_t>::max() << endl ;
  cout << "         on a aussi   SIZE_MAX == " << SIZE_MAX << endl ;
  cout << endl ;    // Ci dessus SIZE_MAX n'est disponible qu'en C++

// Ne compile pas en gcc 5.3.1...
//  cout << "sizeof   (errno_t)    == " << sizeof (errno_t)  << endl ;
//  cout << "sizeof   (rsize_t)    == " << sizeof (rsize_t)  << endl ;
//  cout << "RSIZE_MAX == " << RSIZE_MAX << endl ;

  char c ;
  cout << "sizeof     (char)    : " << sizeof (char) ;
  cout << ", et sizeof c : " << sizeof c << endl ;
  cout<<"Min. char: >" << std::numeric_limits<char>::min() << "<\n" ;
  cout<<"Max. char: >" << std::numeric_limits<char>::max() << "<\n" ;
  cout<<"Min. char: "  << (int)std::numeric_limits<char>::min() << endl ;
  cout<<"Max. char: "  << (int)std::numeric_limits<char>::max() << endl ;
  cout<< endl ;

  // Ci dessous pour le fun de std::numeric_limits< class T>
  cout << std::boolalpha;    // bool affiche "true" ou "false" ci dessous
  cout << "int signe  ? " << std::numeric_limits< int>::is_signed<< '\n';
  cout << "Bits de int: " << std::numeric_limits< int>::digits << '\n';
  cout <<"infini dispo "<<std::numeric_limits< int>::has_infinity<<'\n';

#ifdef ZZZ // GCC: gets() n'existe plus, gets_s() est introuvable
  const size_t SIZE = 1024 ;
  char buf[ SIZE] ;
  std::printf( "Tapez votre n? de carte bleue: ") ;
  std::gets_s( buf, SIZE) ; std::printf( "Vous avez saisi >%s<\n", buf) ;
#endif
}  // fin de fichier
