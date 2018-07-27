// Fichier './Exemples/Associatif.cpp'

#include <string>
#include <map>
#include <iostream>

using namespace std;

int main( void)
{   // Attention ci dessous ' ' obligatoire dans '> >'
    map< string, int, less< string> > Age;

    Age[ "Denis"] = 52;
    Age[ "Edwige"] = 50;
    Age[ "Jacqueline"] = 54;

    cout << "Edwige a " << Age[ "Edwige"] << " ans\n";
}
// Fin de './Exemples/Associatif.cpp'
