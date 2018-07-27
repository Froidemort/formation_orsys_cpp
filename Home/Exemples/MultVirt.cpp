#include <iostream>    // Fichier './Exemples/MultVirt.cpp'
using namespace std ;

class A { 
        public: A() { cout << "A()\n" ; }}; // constructeur

class B {
        public: B() { cout << "B()\n" ; }}; // i.e.

class C : virtual public A {
        public: C() { cout << "C()\n" ; }}; // i.e.

class D : virtual public C {
        public: D() { cout << "D()\n" ; }}; // i.e.

class E : public D, virtual public C, public B {
        public: E() { cout << "E()\n" ; }   // i.e.
} ;

int main( void) {  // -------------------------------------------
    E e ; return 0 ;
}   // Fin de './Exemples/MultVirt.cpp'
