#!/usr/bin/make -rf
# Fichier './Corriges/Rationnel/Makefile'
# Fichier './Rationnel/Makefile' (lien physique)

help:
	@echo
	@echo "make [help]: cette page d'aide"
	@echo "make test1:  teste ... un programme de test"
	@echo "make test2:  teste les differences entre const"
	@echo "make test3:  teste les tests entre rationnels"
	@echo "make test4:  teste les operateurs unaires"
	@echo "make test5:  teste l'operateur -="
	@echo "make test6:  teste l'arrondi au plus proche"
	@echo "make test7:  teste les conversions vers (double)"
	@echo

clean: cleanrep
cleanrep:
	@rm -f *.o Test? *.gch   # '.gch' : entete precompile GCC
	@chmod 644 * ; chmod 755 Makefile

Test1: Test1.cpp Rationnel.h Makefile
	g++ -Wall -o Test1 Test1.cpp
test1: Test1
	./Test1

Test2: Test2.cpp Rationnel.h Makefile
	g++ -Wall -o Test2 Test2.cpp
test2 : Test2
	./Test2

Test3: Test3.cpp Rationnel.h Makefile
	g++ -Wall -o Test3 Test3.cpp
test3 : Test3
	./Test3

Test4: Test4.cpp Rationnel.h Makefile
	g++ -Wall -o Test4 Test4.cpp
test4 : Test4
	./Test4 || exit 0

Test5: Test5.cpp Rationnel.h Makefile
	g++ -Wall -o Test5 Test5.cpp
test5 : Test5
	./Test5

Test6: Test6.cpp Rationnel.h Makefile
	g++ -Wall -o Test6 Test6.cpp
test6 : Test6
	./Test6

Test7: Test7.cpp Rationnel.h Makefile
	g++ -Wall -o Test7 Test7.cpp
test7 : Test7
	./Test7

# Fin de './Rationnel/Makefile'
