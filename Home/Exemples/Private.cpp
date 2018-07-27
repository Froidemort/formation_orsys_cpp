// Fichier './Exemples/Private.cpp'
#define MAIN_CPP_FILE
#include "PrivateClass.cpp"

// class B : public A {  // heritage 'public' : mot clef obligatoire
class B : A {  // heritage 'private' par defaut
    public:
        int b_i ;
        inline void b_f( void) ;
    protected:
        int b_j ;
    private:
        int b_k ;
} ;

inline void B::b_f( void) {
    // Tous les champs de la classe de base conservent leur accessibilite
    // dans la classe derivee. Seul 'private' est inaccessible
    a_i = 1;
    a_f() ;
    a_j = 1 ;
//  a_k = 1 ;     // error: 'int A::a_k' is private
//  ((A*)this)->a_k = 1 ;     // 'private' protege bien le champ
}

// Les erreurs de compilation sont en commentaire
int main( void) {

    B x ;

    // Tous les champs de la classe de base sont vus comme 'private'
    // a travers la classe derivee. Ils sont donc inaccessibles...
//  x.a_i = 1 ;   // error: 'int A::a_i' is inaccessible        //PUB
//  x.a_f() ;     // error: 'void A::a_f()' is inaccessible     //PUB
//  x.a_j = 1 ;   // error: 'int A::a_j' is protected
//  x.a_k = 1 ;   // error: 'int A::a_k' is private

    // ... sauf en tirant parti du faible typage du Langage C !
    (*(A*)&x).a_i = 1 ; // l'heritage prive ne protege rien

}                 // Fin de './Exemples/Private.cpp'
