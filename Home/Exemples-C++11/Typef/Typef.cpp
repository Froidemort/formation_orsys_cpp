// Fichier './Home/Exemples-C++11/Typef/Typef.cpp'

int f( int x) { return x; }
int& g( int& x) { return x; }

int main( void) {  // ------------------------------------------------ 73
    int x=666 ;

    decltype( x)     x_1 ; // identifiant: donc meme type que x 'int'
    decltype( x+12)  x_2 ; // rvalue donc du type 'int'
//  decltype( (x))   x_3 ; // lvalue donc de type 'int&' ne compile pas
//  decltype( ++x)   x_4 ; // lvalue... ne compile pas
    decltype( x++)   x_5 ; // type 'int'
//  decltype( f())   x_6 ; // Ne compile pas il n'y a pas de f( void)
    decltype( f( x)) x_6 ;
    decltype( f)     x_7 ; // type 'int (*)( int)'
                           // NB ci dessus GCC 5.3.1 : pas de warning
//  decltype( g( x)) x_8 ; // type 'int&' et donc ne compile pas

}   // fin de fichier
