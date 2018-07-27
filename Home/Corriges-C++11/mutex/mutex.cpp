// debut de ./Corriges-C++11/mutex/mutex.cpp

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

#define AVEC_UNIQUE_LOCK

void Affiche( // ---------------------------------------------------70
    std::mutex* p,
    int         n,
    char        c
) {
#if defined( AVEC_UNIQUE_LOCK) 
	std::unique_lock< std::mutex> Verrou( *p) ;   // section critique
#else
	p->lock() ;        // debut de section critique
#endif
    for (int i=0; i<n; ++i) { std::cout << c; } 
    std::cout << '\n' ;
#if defined( AVEC_UNIQUE_LOCK) 
	// 'Verrou' disparait et entraine dans sa fin le deverouillage
#else
	p->unlock() ;      // fin de section critique
#endif
}	// fin de Affiche()


int main () { // ---------------------------------------------------70

    std::mutex mtx ; // mtx.unlock() -> inutile -> mutex cree unlocked

    std::thread th1( Affiche, &mtx, 800, 'o');
    std::thread th2( Affiche, &mtx, 800, '+');
    std::thread th3( Affiche, &mtx, 800, '.');
    std::thread th4( Affiche, &mtx, 800, '@');

    th1.join(); th2.join(); th3.join(); th4.join();
    return 0;
}
// fin de fichier
