#!/usr/bin/make -rf 
# Fichier './Corriges/Triangle/Makefile'
# Fichier './Triangle/Makefile'   (lien physique)

SHELL	=	/bin/bash
TAR_FILE=	/tmp/Triangle.tar

help:
	@echo
	@echo "make [help]   : Cette page d'aide"
	@echo "make test     : Compile et lance l'execution"
	@echo "make prog     : Compile le programme de test"
	@echo "make cleanrep : Nettoie le repertoire"
	@echo "make tarrep   : Cree une archive '$(TAR_FILE)'"
	@echo "make version  : Affiche la version des outils"
	@echo

test: Test
Test: Prog
	./Prog

prog: Prog
Prog: Makefile Prog.o Triangle.o Polygone.o
	g++ -o Prog Prog.o Triangle.o Polygone.o

Prog.o: Prog.cpp Triangle.h Polygone.h Makefile
	g++ -c  -Wall --std=c++11 Prog.cpp

%.o: %.cpp %.h Makefile Polygone.h
	g++ -c  -Wall --std=c++11 $*.cpp

tarrep: cleanrep
	@cd .. && tar cf '$(TAR_FILE)' Triangle
	@ls -lh '$(TAR_FILE)'

cleanrep:
	@rm -rf *.o *.tmp '$(TAR_FILE)' *~ ? Prog
	@chmod 644 *
	@chmod 755 Makefile

version:
	@g++  --version | sed '1q'
	@make --version | sed '1q'
	@tar --version | sed '1q'
	@$(SHELL) --version | sed '1q'

# Fin de './Triangle/Makefile'
