// Fichier './Exemples/StdString.cpp'
#include <iostream>
using namespace std ;

int main() { 
   string X( "Marylin") ;

       cout << X << " size()=" << X.size() ;
       cout << " max_size()=" << X.max_size() << endl ;
   X += " Monroe" ;
       cout << X << " size()=" << X.size() << endl ;
   X.append( "...", 3) ;
       cout << "ajoute 3 '.' pour obtenir: " << X << endl ;
   X.resize( X.size() -4) ;
       cout << "retire 4 caracteres: " << X << endl ;
   X.replace( 8, 3, 1, 's') ;
       cout << "a compter position 8, remplace 3 caracteres ";
       cout << "par 1 's': " << X << endl ;
   X.erase( 0, 2) ;
       cout << "efface 2 premiers caracteres: " << X << endl ;
   X.insert( 2, 1, 'l') ;
       cout << "insere 1 'l' en position 2: " << X << endl ;
   X.replace( 0, 2, "ni") ;
       cout << "remplace 2 caracs en pos 0: " << X << endl ;
   X.insert( X.size()-2, "ined") ;
       cout << "insere au milieu: " << X << endl ;
   X.resize( X.length() -2) ;
       cout << "retire 2 caracteres: " << X << endl ;
   X.insert( 2, "a") ;
       cout << "insere 'a' en position 2: " << X << endl ;
   X[ 6] = 'G' ; // Pas de verification sur les debordements
       cout << "met 'G' position 6: " << X << endl ;
   X.at( 12) += 'A' - 'a' ; // Plus sur
       cout << "passe majuscule le carac 12: " << X << endl ;
       cout << "guess what ... " ;

   string::reverse_iterator p;
   for ( p=X.rbegin(); p<X.rend() ; p++) cout << *p ;
   cout << endl ;

}                   // Fin de './Exemples/StdString.cpp'
