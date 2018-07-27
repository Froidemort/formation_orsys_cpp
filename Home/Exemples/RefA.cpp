// Fichier './Exemples/RefA.cpp'
#include <iostream>
using namespace std ;

void Echange( int &n1, int &n2) 
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() 
{
    int i=2, j=3;
    cout << "i= " << i << " j= " << j << endl;

    Echange( i, j);
    cout << "i= " << i << " j= " << j << endl;

}   // Fin de './Exemples/RefA.cpp'
