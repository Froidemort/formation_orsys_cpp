// async example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // 1s

// a non-optimized way of checking for prime numbers:
bool is_prime (int x) {
	using namespace std::chrono_literals;
	std::this_thread::sleep_for( 1s) ;
	for (int i=2; i<x; ++i) if (x%i==0) return false;
	return true;
}

int main()
{
    // call is_prime(313222313) asynchronously:

	std::cout << "Checking whether 313222313 is prime.\n";

	std::future<bool> fut = std::async ( is_prime, 313222313);

	std::cout << "Calculating. Please, wait\n";
	std::chrono::milliseconds	span( 100);
	std::future_status			status ;
	bool						Sortir = false ;
	for (;;) {
		status = fut.wait_for( span) ;
		switch ( status ) {
			case std::future_status::timeout:
				std::cout << "timeout\n" ; break ;
			case std::future_status::deferred:
				std::cout << "deferred\n" ; break ;
		    case std::future_status::ready:
				Sortir=true; std::cout << "ready\n" ; break ;
			default:
				Sortir=true; std::cout << "}Alapo{\n" ; break ;
		} ;
		if ( Sortir ) break ;
		// std::cout << '.' ;
	}

    // get() est bloquante (sinon) attend que l'etat du future soit connu
    bool ret = fut.get();

	if ( ret ) std::cout << "It is prime!\n";
    else std::cout << "It is not prime.\n";

	return 0;
}	// fin de fichier
