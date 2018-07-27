#include <iostream>
#include <utility>
#include <vector>
#include <string>

void Affiche( std::string const& a, std::string const& b, char const* o) {
  std::cout << " a vaut '" << a << "' et b" << " '" << b << "'    " << o << "\n" ;
}

int main()
{ std::cout << std::endl ;
  {
    std::string a ;
    std::string b = "Hello" ;
	Affiche( a, b, " 1) avant a=b;") ;
	a=b;
	Affiche( a, b, "   apres a=b;\n") ;
  }

  { // On recommence la creation ex nihilo des variables
    std::string a ;
    std::string b = "Hello" ;
	Affiche( a, b, "2) avant a=std::move( b);") ;
	a=std::move( b);
	Affiche( a, b, "   apres a=std::move( b);\n") ;
  }

  {
    std::string a ;
    std::string b = "Hello" ;
	Affiche( a, b, "3) avant a=(std::string&&)b;") ;
	a=(std::string&&)b;
	Affiche( a, b, "   apres a=(std::string&&)b;\n") ;
  }

  {	// b est ... ? une lvalue en fait. Une reference sur une rvalue ne peut pas etre dans une variable
    // en quelque sorte: elle devient une lvalue!
    std::string a ;
    std::string&& b = "Hello" ;
	Affiche( a, b, "4) avant a=b; ou std::string&& b;") ;
	a=b;
	Affiche( a, b, "   apres a=b; ou std::string&& b;\n") ;
  }

  {
    std::string a ;
    std::string&& b = "Hello" ;
	Affiche( a, b, "5) avant a=(std::string&&)b; ou std::string&& b;") ;
	a=(std::string&&)b;
	Affiche( a, b, "   apres a=(std::string&&)b; ou std::string&& b;\n") ;
  }

  {
    std::string a ;
    std::string const& b = "Hello" ;
	Affiche( a, b, "6) avant a=b; ou std::string const& b;") ;
	a=b;
	Affiche( a, b, "   apres a=b; ou std::string const& b;\n") ;
  }

  {
    std::string a ;
    std::string const& b = "Hello" ;
	Affiche( a, b, "7) avant a=std::move( b); ou std::string const& b;") ;
	a=std::move( b);
	Affiche( a, b, "   apres a=std::move( b); ou std::string const& b;\n") ;
  }

  {
    std::string a ;
    std::string const& b = "Hello" ;
	Affiche( a, b, "8) avant a=(std::string&&)b; ou std::string const& b;") ;
	a=(std::string&&) b;
	Affiche( a, b, "   apres a=(std::string&&)b; ou std::string const& b;\n") ;
  }

  {
    std::string a ;
    std::string const b = "Hello" ;
//	b = "" ;	// Ne compile pas car b est 'const'
	Affiche( a, b, "9) avant a=(std::string&&)b; ou std::string const b;") ;
	a=(std::string&&) b;
	Affiche( a, b, "   apres a=(std::string&&)b; ou std::string const b;\n") ;
	std::cout << "b==>" << b << "< !\n" ;
//	b = "essai" ;	// Ne compile pas car b est 'const'
  }
  return 0 ;
} // fin de fichier
