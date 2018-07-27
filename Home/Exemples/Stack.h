// Fichier './Exemples/Stack.h'
#include <stdexcept>
using namespace std ;
const int max_pile = 100 ;

class Stack {
  public:
    Stack() : indice( -1) {}
    ~Stack() {}
    inline void push( int val) ;
    inline int pop() ;
    enum { capacite = max_pile } ; // Simule une 'const'

  private:
    int data[ max_pile]; int indice;
} ; 

inline void Stack::push( int val) {
    if ( indice >= max_pile-1 )
        throw overflow_error( "oups! La pile est pleine");
    data[ ++indice] = val ;
}

inline int Stack::pop( void) {
    if ( indice < 0 )
        throw underflow_error( "boum! La pile est vide") ;
    return data[ indice--] ;
}                           // Fin de './Exemples/Stack.h'
