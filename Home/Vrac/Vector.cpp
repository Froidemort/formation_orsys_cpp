#include <vector>
#include <iostream>
using namespace std ;

typedef vector<int> vInt ;

void foo( vInt &v) {
	v.push_back( 13) ;
	return ;
}

main( )
{
	vInt I ;
	foo( I) ;
	cout << I.front() ;
}
