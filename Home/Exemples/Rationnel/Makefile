# Debut de './Exemples/Rationnel/Makefile'

# Marche pas terrrible ce Makefile

all: T1 T2 T3 T4 T5 T6

clean:
	@rm -f T? *.o a.out

T1: Makefile Rationnel.h Test1.cpp
	g++ -Wall -o T1 Test1.cpp

T2: Makefile Rationnel.h Test2.cpp Part2.h Pgcd.h
	g++ -Wall -o T2 Test2.cpp -DPART2

T3: Makefile Rationnel.h Test3.cpp Part2.h Pgcd.h Part3.h
	g++ -Wall -o T3 Test3.cpp -DPART3

T4: Makefile Rationnel.h Test4.cpp Part2.h Pgcd.h Part3.h Cout.h Part4.h
	g++ -Wall -o T4 Test4.cpp -DPART4

T5: Makefile Rationnel.h Test5.cpp Part2.h Pgcd.h Part3.h Cout.h Part4.h Part5.h Part6.h
	g++ -Wall -o T5 Test5.cpp -DPART5

T6: Makefile Rationnel.h Test6.cpp Part2.h Pgcd.h Part3.h Cout.h Part4.h Part5.h Part6.h
	g++ -Wall -o T6 Test6.cpp -DPART5

# fin de fichier
