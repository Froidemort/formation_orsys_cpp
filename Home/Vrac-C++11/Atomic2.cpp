// Debut de ./Home/Atomic/Atomic.cpp

#include <thread>   //  std::thread
#include <iostream> //  std::cout
// #include <cstdlib>  //  std::abort()

class Obj {
  public:
    Obj( void) : _char( 'A') {}
  public:
    void operator()( void) {
		for ( ;; ) {
			if (      _char == 'A' ) { _char += 'a' ; _char -= 'A' ; }
			else if ( _char == 'a' ) { _char += 'A' ; _char -= 'a' ; }
			else {
				std::cout << "condition inattendue >" << _char ;
				std::cout << "< dans Obj::operator()\n" ;
				std::abort() ;
			}
		}
    }
  private:
    char _char ;
} ;

static Obj O ;

int main( void) {

    std::thread T1( O) ;
    std::thread T2( O) ;
    std::thread T3( O) ;
    std::thread T4( O) ;

    T1.join() ;
	T2.join() ; T3.join() ; T4.join() ;
    std::cout << "\nfin du programme\n" ; return 0;
}   // fin de fichier
