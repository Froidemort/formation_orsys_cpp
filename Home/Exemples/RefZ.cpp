// Fichier './Exemples/RefZ.cpp'
int main( void) {
  int x=9 ;
  int &y = x ;       // y et x designent la meme variable entiere
//  int &z ;    // error: 'z' declared as reference but not initialized
  const int &u = x ;
//  u++ ;       // error: increment of read-only reference 'u'
  x++ ;              // modifie 'u' tout de meme... :o(
  const int &v = 7 ;
//  int &w = 9 ;// error: invalid initialization of non-const reference
  int *pi ;          // un banal pointeur du C 
  int *&pj = pi ;    // 'pj' est une reference vers un type 'int *'
  return 0 ;
} // Fin de './Exemples/RefZ.cpp'
