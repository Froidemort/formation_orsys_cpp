// Debut de Home/func_ptr/func_ptr.cpp
#include <iostream>
#include <memory>


class Contact { // ------------------------------------------------ 70
  public:
    Contact( auto Nom, auto Age, auto Salaire) noexcept :
		_Nom( Nom), _Age( Age), _Salaire( Salaire) {}
	void AfficheNom( void) const noexcept {
	    std::cout << "nom: " << _Nom << '\n' ;
	}
	static Contact& CreeNouveauContact( auto Nom, auto Age, auto Sal) {
		return *new Contact( Nom, Age, Sal) ;
    }
  private:
	std::string _Nom ;
    int _Age ;
	double _Salaire ;
} ;



int main() { // --------------------------------------------------- 70
    Contact& Denis=Contact::CreeNouveauContact( "Denis", 59, 1000.0) ;
    Denis.AfficheNom() ;
    delete &Denis ;
}   // fin de fichier
