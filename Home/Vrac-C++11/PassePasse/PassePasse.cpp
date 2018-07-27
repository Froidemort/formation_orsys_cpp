#include <iostream>

// dans la vie on a des sous qui sont deplaces, quand je fais un cheque

static int Generateur =0 ;
class PP { // La classe contient des 'objets' identifies par une variable statique
	public:
		PP( void) {
			_Id = ++Generateur ;
			std::cout << "ctor de PP vide: pp(" << _Id << ")\n" ;
		}
		~PP() {
			std::cout << "dtor du pp(" << _Id << ")\n" ;
		}
		int GetId( void) const { return _Id ; }
		void InvallideId( void) { _Id=0 ; }		// Pour indiquer une objet invalide
// #ifdef CORRECTION
// ----------------------------------------------- ci dessous corrections
		PP( PP const& pp) {
			_Id = ++Generateur ;
			std::cout << "ctor de PP par copie : pp(" << _Id << ")\n" ;
		}
		PP& operator= ( PP const& pp) {
			std::cout << "copie pp( " << pp.GetId() << ") dans pp( " << GetId() << ")\n" ;
			return *this ;
		}
/*		PP( PP&& r) {
			_Id = r.GetId() ;
			r.InvallideId() ;
			std::cout << "ctor de PP par transfert : pp(" << _Id << ")\n" ;
		}
*/ // -----------------------------------------------
// #endif
	private:
		int _Id ;
} ;




int main( void) {

	std::cout << "Avant creation des 3 petits PP par appel au constructeur vide\n" ;
	PP p1, p2, p3 ;
//	PP p( 5) ;		// Doit echouer: pas de ctor

	// Creation de p4 par copie de p1 BUG : pouvez-vous corriger ?
	std::cout << "Avant creation de p4 par copie de p1\n" ;
	PP p4( p1) ;	// ou 'PP p4=p1 ;'
	PP& q = p4 ;	// Pas de nouvel objet, reference de lvalue (nouveau nom)
	q = p1 ;		// Manipule p4 par reference en mettant p1 dans p4

	// Creation d'un PP vide auquel on affecte un PP. BUG
	std::cout << "Avant creation de p5 vide; on lui affecte ensuite p2\n" ;
	PP p5 ; p5 = p2 ;
	
	std::cout << "Avant creation d'une rvalue qui disparait illico: p6\n" ;
	PP() ;	// Cree un objet de type rvalue, p6: on le perd immediatement

	std::cout << "Avant creation d'une rvalue qui perdure dans une reference a une rvalue\n" ;
	PP&& p7 = PP() ;// p7 est une reference de rvalue qui du coup perdure

	std::cout << "Avant creation de p8 par transfert d'une rvalue\n" ;
//	PP p8( PP( 1)) ;	// manque le constructeur
	PP p8( PP{}) ;
//	PP p8( PP()) ;		// PP() ne fait rien et du coup pas de p8... Bizare
//	PP p8( std::move( PP())) ;	// Quel sera le numero de p8 ?
//	PP p8( p7) ;

	std::cout << "Avant creation de p9\n" ;
	PP p9 ;

	std::cout << "Fin de programme\n" ;
}
