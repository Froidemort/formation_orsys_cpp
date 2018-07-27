#! /usr/bin/make -f
# Makefile passe-partout pour projets de noms identiques a celui des repertoires

VERSION				:=	1.02 (27 febbraio 2016)
INITIAL_VERSION		:=	1.00 (24 febbraio 2016)
SHELL				:=	/bin/bash
PRGM				:=	$(shell echo $${PWD\#\#*/})


help:
	@echo
	@echo "make [help]  : Cette page d'aide concernant '$(PRGM)'"
	@echo "make cleanrep: Nettoie le repertoire"
	@echo "make cleantxt: Supprime le fichier $(PRGM).txt"
	@echo "make test    : Compile et Lance le test"
	@echo "make txt     : Fabrique un fichier '$(PRGM).txt' de resultat"
	@echo "make val     : Compile et Lance le test depuis valgrind"
	@echo "make versions: Versions des differents outils"


test: $(PRGM)
	@./$(PRGM)


valgrind: val
val: $(PRGM)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(PRGM)


$(PRGM): Makefile $(PRGM).cpp
	@g++ -g $(CXXFLAGS) $(LDFLAGS) $(PRGM).cpp -o $(PRGM)


                 # '$@' designe la cible dans un Makefile
c++98:
	g++ -g -Wall -std=$@ $(LDFLAGS) $(PRGM).cpp -o $(PRGM)
c++03:
	g++ -g -Wall -std=$@ $(LDFLAGS) $(PRGM).cpp -o $(PRGM)
c++11:
	g++ -g -Wall -std=$@ $(LDFLAGS) $(PRGM).cpp -o $(PRGM)
c++14:
	g++ -g -Wall -std=$@ $(LDFLAGS) $(PRGM).cpp -o $(PRGM)
c89:
	cc -g -Wall -x c -std=$@ $(LDFLAGS) $(PRGM).cpp -o $(PRGM)	# -x 'language'
c99:
	cc -g -Wall -x c -std=$@ $(LDFLAGS) $(PRGM).cpp -o $(PRGM)	# -x 'language'
c11:
	cc -g -Wall -x c -std=$@ $(LDFLAGS) $(PRGM).cpp -o $(PRGM)	# -x 'language'


cleanrep:
	@rm -f *.o *.tmp tmp* ? $(PRGM)
	@chmod 755 Makefile
	@chmod 2>/dev/null 444 *.txt || exit 0


cleantxt:
	@rm -f $(PRGM).txt


txt:
	@chmod 2>/dev/null 644 *.txt || exit 0
	@make --quiet --no-print-directory $(PRGM)
	@./$(PRGM) >$(PRGM).txt
	@chmod 2>/dev/null 444 *.txt || exit 0
	@ls -l | sed 's/^total.*//'


versions:
	@echo "Systeme     : $$(hostnamectl| sed -n '/Operating/p'| sed 's/.*: //')"
	@echo "Compilateur : $$(g++ --version | sed 'q')"
	@echo "make        : $$(make --version | sed 'q')"
	@echo "Verificateur: $$(valgrind --version)"

# fin du Makefile
