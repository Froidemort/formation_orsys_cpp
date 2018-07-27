// Fichier './Exemples/Stacklate.cpp'

#include <iostream>
using std::cout ; using std::endl ;

template< class T, int size=1023> // Pas de 'T' par defaut
class Stack {
  public:
    Stack() : index( -1) {}
    ~Stack() {}
    void push( const T &val) {    // Pas de copie inutile
        data[ ++index] = val ;
    }
    T &pop() {                    // Pas de copie inutile
        return data[ index--];
    }
    enum { Size = size } ;

  private:
    T data[ size];
    int index;
}; 

int main( void) {
    Stack< char, 100> pile ;

    Stack< int> essai ;
    cout << "essai     : " << essai.Size << endl ;
    cout << "Par defaut: " << Stack< int>::Size << endl ;

    pile.push( 'a') ;
    pile.push( 'b') ;
    pile.push( 'c') ;

    cout << pile.pop() << endl ;
    pile.push( 'd') ;
    ((cout << pile.pop()) << " - " << pile.pop()) << " + " << pile.pop();
    cout << endl ;

    int i = 0 ; // On se mefiera des regles de preseance en C++,
                // qui ne sont pas respectees selon les operateurs du C,
                // puisque la surcharge les remplace par l'operateur
                // 'Appel de fonction'. CQFD. Comme ci dessous...
    cout << i++ << " : " << i++ << endl ; // compile avec warning
    // Stacklate.cpp: In function 'int main()':
    // Stacklate.cpp:36: warning: operation on 'i' may be undefined
    return 0 ;
}

// Fin de './Exemples/Stacklate.cpp'
