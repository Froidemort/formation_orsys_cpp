// Debut de Home/func2_ptr/func2_ptr.cpp
#include <iostream>
#include <memory>
using std::unique_ptr ;

class Contact { // ------------------------------------------------ 70
  public:
    Contact( auto Nom, auto Age, auto Salaire) noexcept :
		_Nom( Nom), _Age( Age), _Salaire( Salaire) {
	    std::cerr << "(debug) ctor: " << _Nom << '\n' ;
	}
	~Contact() noexcept {
	    std::cerr << "(debug) dtor: " << _Nom << '\n' ;
	}
	void AfficheNom( void) const noexcept {
	    std::cout << "nom: " << _Nom << '\n' ;
	}
  private:
	std::string _Nom ;
    int _Age ;
	double _Salaire ;
} ;


unique_ptr< Contact> CreeNouveauContact(  // ---------------------- 70
		auto Nom, auto Age, auto Sal
){
    std::cerr << "(debug) entre dans " << __func__ << '\n' ;
	return 
		std::move( unique_ptr< Contact>( new Contact( Nom, Age, Sal))
	);
}


int main() { // --------------------------------------------------- 70
    unique_ptr< Contact> p( 
		std::move( CreeNouveauContact( "Denis", 59, 1000.0))
	);
	std::cerr << "(debug) sizeof  p == " << sizeof  p << '\n' ;
	std::cerr << "(debug) sizeof *p == " << sizeof *p << '\n' ;
    p->AfficheNom() ;
    return 0  ;
}   // fin de fichier
