// debut de ./Exemples-C++11/Swap/Swap.cpp
#define SWAP_CPP_FILE
#define AVEC_CTOR_MOVE                // Ne pas modifier cette ligne - 73
#include "../NewCtor/NewCtor.cpp"

#define AVEC_STD_MOVE                 // ... mais celle la seulement

#if defined( AVEC_STD_MOVE)
    template< class T>                // NB. il n'y a pas de confusion
    void swap( T& a, T& b) {          //     possible entre T qui est le
                                      //     nom d'une classe, et T local
        T tmp( std::move( a));        //     ici qui designe n'importe
        a = std::move( b);            //     quelle classe.
        b = std::move( tmp);
    }
#else
    template< class T>
    void swap( T& a, T& b) {

        T tmp( a);
        a = b;
        b = tmp;
    }
#endif

int main( void) {  // ------------------------------------------------ 73

    T A( "Aaaaa"), B( "Bbbb") ;
    std::cerr << "\navant le swap()\n";
    std::cerr << "A : " ; A.Dump() ;
    std::cerr << "B : " ; B.Dump() ;
    swap( A, B) ;
    std::cerr << "\net apres le swap()\n";
    std::cerr << "A : " ; A.Dump() ;
    std::cerr << "B : " ; B.Dump() ;
    std::cerr << "\nfin de programme\n" ; return 0 ;
}   // fin de fichier
