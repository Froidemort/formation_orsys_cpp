// Debut de ./Home/Exemples-C++11/Foncteur/Foncteur.cpp
#include <iostream>			// std::cout
#include <thread>			// std::thread std::this_thread
#include <functional>		// std::ref
#include <chrono>			// std::chrono::seconds()

#define PARALLEL
// #define NOCOPY

class Objet { // ----------------------------------------------------- 73
  public:
    Objet( void)           { std::cout << "ctor vide\n";  }
    Objet( Objet const& o) { std::cout << "ctor copie\n"; }
    ~Objet()               { std::cout << "dtor\n";       }

	// Surcharge de l'operateur "Appel de fonction" sans argument
    void operator()( void) const {
        std::cout << "debut de travail du thread sans arg\n";
        std::this_thread::sleep_for( std::chrono::seconds( 3) );
        std::cout << "  fin de travail du thread sans arg\n";
    }

	// Surcharge de l'operateur "Appel de fonction" avec un int
    void operator()(  int n) const {
        std::cout << "debut de travail du thread arg=" << n << '\n' ;
        std::this_thread::sleep_for( std::chrono::seconds( 3) );
        std::cout << "  fin de travail du thread arg=" << n << '\n' ;
    }
} MonObjet ;



int main() { // ------------------------------------------------------ 73
#ifdef PARALLEL
	#ifdef NOCOPY
		std::thread t( std::ref( MonObjet), 777);
		std::thread r( std::ref( MonObjet));
	#else
		std::thread t( MonObjet);
		std::thread r( MonObjet, 666);
	#endif
    std::this_thread::sleep_for( std::chrono::seconds( 1) );
	std::cout << "... execution dans main() en parallele\n" ;
    t.join();			// sinon terminate without an active exception
    r.join();
#else
	MonObjet() ;
	MonObjet( 44) ;
	std::cout << "... execution dans main() a la suite\n" ;
#endif
	return 0 ;
}						// fin de fichier
