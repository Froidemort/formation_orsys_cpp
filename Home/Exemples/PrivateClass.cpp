// Fichier './Exemples/PrivateClass.cpp'

class A {
    public:
        int a_i ;
        inline void a_f( void) ;
    protected:
        int a_j ;
    private:
        int a_k ;
} ;

inline void A::a_f( void) { a_i = a_j = a_k = 0 ; }

#ifndef MAIN_CPP_FILE
// Les erreurs de compilation sont en commentaire
int main( void) {

    A x ;

    x.a_i = 1 ;
    x.a_f() ;
//  x.a_j = 1 ;   // error: 'int A::a_j' is protected
//  x.a_k = 1 ;   // error: 'int A::a_k' is private

}
#endif         // Fin de './Exemples/PrivateClass.cpp'
