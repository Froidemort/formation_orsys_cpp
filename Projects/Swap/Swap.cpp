#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void swap(double &x, double &y) {
	double &temp = x ;
	cout << "On passe dans cette fonction !\n" ;
	x = y ;
	y = temp ;
};

int main(){
	double i = 5.25 ; double j = 3.141592 ;
	//int i = 4; int j = 5 ;
	//char i = 'a'; char j = 'b' ;
	//string i  = "Hello"; string j = "World" ;
	cout << i << " " << j << endl;
	swap(i, j);
	cout << i << " " << j << endl;
	return 0;
}