#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>

class Test {

  public:
    Test( const char * Name ): name( Name ) {}

    ~Test() {
        std::cout << "Destruction de " << this->name << '\n'; 
    }
    
    void printName() { 
        std::cout << this->name << '\n' ; 
    }

  private:
    std::string name;
} ;



// declaration du type pointeur intelligent sur Test
typedef boost::shared_ptr<Test> TestPtr;



int main()
{
    // pointeur initialise a NULL
    TestPtr ptr;					// pointeur initialise a NULL


    // pointeur temporaire detruit a la fin d'un bloc
    {
        TestPtr ptr_tmp( new Test( "objet1" ) );

        // initialise ptr avec ptr_tmp
        ptr = ptr_tmp;
    } // ici, ptr_tmp est detruit, mais ptr reste valide
    ptr->printName(); // OK, affiche "objet1"


    // reinitialiser le pointeur avec un nouvel objet
    // objet1 est detruit, objet2 est cree
    ptr.reset( new Test( "objet2" ) );
    ptr->printName(); // OK, affiche "objet2"


    // copie du pointeur sur objet2
    TestPtr ptr2 = ptr;


    // mise a NULL de ptr
    ptr.reset(); // rien ne se passe


    // mise a NULL de ptr2
    ptr2.reset(); // objet2 est detruit


    // utilisation du pointeur NULL : erreur en mode Debug
    ptr->printName(); // Assertion failed: px != 0
}

