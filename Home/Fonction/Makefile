#! /usr/bin/make -f
# Makefile passe-partout pour projets de noms identiques a celui des repertoires

VERSION				:=	1.13 - 01 agosto 2016
# INITIAL_VERSION		:=	1.00 - 24 febbraio 2016
SHELL				:=	/bin/bash
PRGM				:=	$(shell echo $${PWD\#\#*/})
CPP_FILES			:=	$(wildcard *.cpp)
H_FILES				:=	$(wildcard *.h)

# Pour memoire CXX designe le compilateur C++ et CPP le preprocesseur
#CXX					:= g++-6
CXX					:= g++
#CXX					:= clang++ -Wno-invalid-source-encoding
CC					:= gcc
CXXFLAGS			:= -Wall -g -pthread
LDFLAGS				:=
CFLAGS				:= -Wall -g -x c -pthread


help:
	@echo
	@echo "make [ help ] : Cette page d'aide concernant '$(PRGM)'"
	@echo "make cleanrep : Nettoie le repertoire"
	@echo "make cleantxt : Supprime le fichier $(PRGM).txt"
	@echo "make test     : Compile et Lance le test"
	@echo "make txt      : Fabrique un fichier '$(PRGM).txt' de resultat"
	@echo "make val      : Compile et Lance le test depuis valgrind"
	@echo "make versions : Versions des differents outils"


test: $(PRGM)
	@./$(PRGM)


valgrind: val
val: Makefile $(CPP_FILES) $(H_FILES)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(PRGM)


$(PRGM): Makefile $(CPP_FILES) $(H_FILES)
	@$(CXX) $(CXXFLAGS) -std=c++11 $(LDFLAGS) $(CPP_FILES) -o $(PRGM)


# '$@' designe la cible dans un Makefile
# l'option '-x' specifie le langage a compiler
c++98:
	$(CXX) $(CXXFLAGS) -std=$@ $(LDFLAGS) $(CPP_FILES) -o $(PRGM)
c++03:
	$(CXX) $(CXXFLAGS) -std=$@ $(LDFLAGS) $(CPP_FILES) -o $(PRGM)
c++11:
	$(CXX) $(CXXFLAGS) -std=$@ $(LDFLAGS) $(CPP_FILES) -o $(PRGM)
c++14:
	$(CXX) $(CXXFLAGS) -std=$@ $(LDFLAGS) $(CPP_FILES) -o $(PRGM)
c++17:
	$(CXX) $(CXXFLAGS) -std=$@ $(LDFLAGS) $(CPP_FILES) -o $(PRGM)
c89:
	$(CC)  $(CFLAGS)   -std=$@ $(LDFLAGS) $(CPP_FILES) -o $(PRGM)
c: c99
c99:
	$(CC)  $(CFLAGS)   -std=$@ $(LDFLAGS) $(CPP_FILES) -o $(PRGM)
c11:
	$(CC)  $(CFLAGS)   -std=$@ $(LDFLAGS) $(CPP_FILES) -o $(PRGM)


cleanrep:
	@rm -f *.o *.tmp tmp* ? core vgcore* $(PRGM)
	@chmod 644 *
	@chmod 755 Makefile
	@chmod 2>/dev/null 444 *.txt || exit 0


cleantxt:
	@rm -f $(PRGM).txt


txt:
	@chmod 2>/dev/null 644 *.txt || exit 0
	@make --quiet --no-print-directory $(PRGM)
	@./$(PRGM) >$(PRGM).txt 2>&1
	@chmod 2>/dev/null 444 *.txt || exit 0
	@ls -l | sed 's/^total.*//'
	@cat $(PRGM).txt


version:
	@echo
	@echo "     Version du Makefile"
	@echo "Makefile : $(VERSION)"
	@echo

versions: version
	@echo "     Version des outils"
	@echo "Systeme      : $$(hostnamectl| sed -n '/Operating/p'| sed 's/.*: //')"
	@echo "g++          : $$($(CXX) --version | sed 'q')"
	@echo "clang++      : $$(clang --version | sed 'q')"
	@echo "make         : $$(make --version | sed 'q')"
	@echo "Verificateur : $$(valgrind --version)"
	@echo
	@echo "     Options des compilations en C"
	@echo "Compilateur  : $(CC)"
	@echo "CFLAGS       : $(CFLAGS)"
	@echo
	@echo "     Options des compilations en C++"
	@echo "Compilateur  : $(CXX)"
	@echo "CXXFLAGS     : $(CXXFLAGS)"
	@echo

# Option technique permettant de verifier depuis le Makefile de ./Home que
# le compilateur active par defaut est bien 'g++'
CXX: cxx
cxx:
	@echo "$(CXX)"


# fin du Makefile
