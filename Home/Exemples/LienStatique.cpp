// Fichier './Exemples/LienStatique.cpp'

#include <iostream>
using namespace std ;


class Polygone {
    protected:
        int a, b, c, d;
    public:
        Polygone( int x, int y, int z, int t)
          { a=x; b=y; c=z; d=t ; }
        void Affiche( void) const {
          cout << "Polygone --- " << a << " ...\n" ; }
} ;


class Rectangle : public Polygone {
    public:
        Rectangle( int x, int y) : Polygone( x, y, x, y) {}
        void Affiche( void) const {
             cout << "Rectangle --- " << a << " ...\n" ; }
} ;



int main( // -------------------------------------------------------- 72
     void
) {
    Polygone P( 5,3,5,3) ; Polygone  *pP = &P ;
    Rectangle R( 2, 4) ;   Rectangle *pR = &R ;
    Polygone &rP = R ;

    cout << "Poly :" ; pP->Affiche() ;
    cout << "Rect :" ; pR->Affiche() ;
    cout << "  rP :" ; rP.Affiche() ;

    cout << "\nLe developpeur C \"bricole\" les branchements:\n" ;

    pR = (Rectangle *) &P ; cout << "Poly vu comme Rect : " ;
         pR->Affiche() ;
    pP = (Polygone *)  &R ; cout << "Rect vu comme Poly : " ;
         pP->Affiche() ;

    cout << "\nLe branchement est genere a la compilation\n" ;

    return 0 ;
}   // fin de fichier
