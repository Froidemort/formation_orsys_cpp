// Joueur.h
#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <iostream>
#include "../include/Tour.h"

#define SCORE_MAX 4000
using std::string;
using std::cin;
using std::cout;
using std::endl;


class Joueur {
private:
	string _Nom ;
	int mon_score ;
public:
	virtual ~Joueur(void) {}
	Joueur(string nom) : _Nom(nom), mon_score(0){}

	string const &Nom(void) const { return _Nom ;}

	void Affiche(void) { cout << "MON SCORE : " << mon_score << "\n"  ;}
	int const &score(void) const {return mon_score ;}
	void set_score(int new_score) {mon_score+=new_score ;}
	bool Gagne(void) {
		if (score() >= SCORE_MAX ) {
			return true;
		} 
		else {
			return false;
		}	
	} ;
	virtual void Joue(void) {} ;

} ;


class JoueurManuel: public Joueur {
	public:
		~JoueurManuel() {cout << "Destruction de JoueurManuel\n";}
		JoueurManuel(string nom): Joueur(nom) {};

		void Joue(void) {
	    	Tour T ;
	    	bool continuer = true;
	    	string another_one;
	    	do {
	    		(void)T.nouveau_lancer();
	    		if (T.score() == 0) {
	    			break;
	    		}
	    		T.Affiche();
	    		cout << "Another one ?\n";
	    		cin >> another_one ;
	    		if (another_one != "yes"){
	    			continuer = false;
	    			break;
	    		}
	    		//***
	    	} while (continuer);

    T.Affiche() ;
    set_score(T.score());
    };	

};

class JoueurAuto: public Joueur {
	public:
		~JoueurAuto() {cout << "Destruction de JoueurAuto\n";}
		JoueurAuto(string nom): Joueur(nom) {};
		void Joue(void) {
    	Tour T ;
    	bool continuer = true;
	    do {
	        (void)T.nouveau_lancer() ;
	    	if (T.score() == 0) {
	    		break;
	    	}
	    	T.Affiche();
	        if (T.score() > 1000) {
	        	continuer = false;
	        	break;
	        } 
		 } while ( T.score() || continuer ) ;
    T.Affiche() ;	
    set_score(T.score());    
    };	

};

#endif // DE_H


// end Joueur.h