// Fichier './Exemples/CatchNew.cpp'  -- new et exceptions

#include <iostream>  // pour std::cerr std::cout
#include <stdlib.h>  // pour abort()
using namespace std ;

//const unsigned long TAB = (unsigned long)(-1) ;
const unsigned long TAB = (unsigned long)13 ;

int main ( void) {

  char *MonString ;  // *MonString va exister au dela du try {} catch ()
                     // c'est pourquoi 'MonString' est hors du try {}
  try {
    MonString = new char [ TAB];

    for ( unsigned long n=0L; ; n++) // remplit le tableau par des 'o'
      if ( n>=TAB ) throw n ;        // empile la taille du tableau cree
      else MonString[ n]='o' ;       // initialise tous les elements

  } catch ( unsigned long i) {
      cout << "Le tableau est bien cree, de taille " << i << endl ;

  } catch ( std::bad_alloc X) {  // ou plus simplement 'bad_alloc'
      cerr << "Oups, erreur d'allocation, on se quitte" << endl ;
      abort() ;

  } catch ( ...) {
      // Une erreur que le developpeur n'imagine pas...
      // 'grep' vous retrouvera cette ligne illico rapido
      cerr << "Erreur fatale 213254276\n" ;
      abort() ;

  }
  cout << "Tout va bien :" << *MonString << ") on desalloue, bye" << endl ;
  delete [] MonString ;
  return 0 ;
}                          // Fin de './Exemples/CatchNew.cpp'
