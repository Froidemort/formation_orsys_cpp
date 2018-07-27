// Debut de ./Home/Thread-Obj/Thread-Obj.cpp

#include <thread>   //  std::thread
#include <iostream> //  std::cout

class Obj {
  public:
    Obj( char c) : _char( c) {}
  public:
    void operator()( void) {
        for ( int i=0 ; i<500; i++ ) std::cout << _char ;
    }
  private:
    char _char ;
} ;

int main( void) {

    std::thread T1( Obj( 'A'+0)) ;
    std::thread T2( Obj( 'A'+1)) ;
    std::thread T3( Obj( 'A'+2)) ;

    T1.join() ; T2.join() ; T3.join() ; 
    std::cout << "\nfin du programme\n" ; return 0;
}   // fin de fichier
