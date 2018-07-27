// debut de ./mutex/mutex.cpp

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex


void Affiche( 
//	std::mutex& mtx,
	int n,
	char c
) {
//  mtx.lock() ;		// debut de section critique
    for (int i=0; i<n; ++i) { std::cout << c; }
	std::cout << '\n' ;
//	mtx.unlock() ;	    // fin de section critique
}


int main ()	{ // ---------------------------------------------------70

//	std::mutex mtx ;
//  std::thread th1 (Affiche, mtx, 800, 'o');
//	std::thread th2 (Affiche, mtx, 800, 'x');

    std::thread th1 (Affiche, 800, 'o');
	std::thread th2 (Affiche, 800, 'x');

    th1.join(); th2.join();
    return 0;
}	// fin de main()
// fin de fichier
