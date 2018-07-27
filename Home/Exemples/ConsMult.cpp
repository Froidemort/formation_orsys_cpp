#include <iostream>    // Fichier './Exemples/ConsMult.cpp'
using namespace std ;

class A { 
        public: A() { cout << "A()\n" ; }}; // constructeur

class B {
        public: B() { cout << "B()\n" ; }}; // i.e.

class C : public A {
        public: C() { cout << "C()\n" ; }}; // i.e.

class D : public C {
        public: D() { cout << "D()\n" ; }}; // i.e.

class E : public D, public C, public B {
        public: E() { cout << "E()\n" ; }   // i.e.
} ;

int main( void) {  // -------------------------------------------
    E e ; return 0 ;
}   // Fin de './Exemples/ConsMult.cpp'
