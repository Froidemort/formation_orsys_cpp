#include <iostream>

class Une {
  public:
	Une( std::string	s) : _Rien( s) {}

  public:
	char const* operator()( void) { return _Rien.c_str() ; }

  private:
    std::string		_Rien ;
} ;

class Derive : public Une {
  public:
	Derive( void) : Une( "derivee\n") {}
} ;


int main( void) {

	Derive d ;
	std::cout << d() ;
}

