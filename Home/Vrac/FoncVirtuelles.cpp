
#include <iostream>

class Polygone {
	public : virtual void affiche( void) const throw() { std::cout << "Polygone\n" ; }
	         virtual ~Polygone() {}
} ;

class Carre : public Polygone {
	public : virtual void affiche( void) const throw() { std::cout << "Carre\n" ; }
	         virtual ~Carre() {}
			 virtual void essai( void) const throw() { std::cout << "... essai\n" ; }
} ;


int main() {

	Polygone a ; Carre b ;
	a.affiche() ;		// Carre ou Polygone ?

	Polygone* q = &b ;
	q->affiche() ;		// Carre ou Polygone ?

	Polygone& r = b ;
	r.affiche() ;		// Carre ou Polygone ?

	Polygone& r = *(Polygone*)&b ;
	r.affiche() ;		// Carre ou Polygone ?
	r.essai() ;

	return 0 ;
}
