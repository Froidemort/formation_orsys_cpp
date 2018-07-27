#include <iostream>

void foo( void) {
	// La reference n'est pas 'naturelle' pour manipuler un tableau
	int& p = *new int [ 3] ;
	std::cerr << "Taille de p: " << sizeof p ;
	std::cerr << " (attendu: " << 3 * sizeof (int) << " octets)\n" ;
//	delete &p ;				// instruction erronee pour tester valgrind
//	delete [] &p ;			// instruction correcte
}

void goo( void) {
	int* p = new int [ 5] ;
	std::cerr << "Taille de p: " << sizeof p ;
	std::cerr << " (attendu: " << 5 * sizeof (int) << " octets)\n" ;
	p[ 0]=100; p[ 1]=101; p[ 2]=102 ; 	// ... 
//	delete p ;				// instruction erronee pour tester valgrind
//	delete [] p ;			// instruction correcte

}

int main( void) {

	char& s = *new char [ 17] ;
	s = 'O' ; (&s)[1]='u' ; (&s)[2]='p' ; (&s)[3]='s' ; (&s)[4]='\0' ;

	std::cerr << "Taille de s: " << sizeof s ;
	std::cerr << " (attendu: " << 17 * sizeof (char) << " octets)" ;
	std::cerr << " Contenu  : >" << s ;
	std::cerr << "< Ou mieux : >" << &s << "<\n" ;
	foo() ; goo() ;
//	delete [] &s ;
	return 0 ;
}
