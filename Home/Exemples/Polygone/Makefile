# Fichier './Exemples/Polygone/Makefile'

# Ce Makefile fabrique l'exercice base sur les triangles dans le 			# SRC_ONLY
# repertoire 'Polygone' du stagiaire par 'make home'						# SRC_ONLY
# Les lignes marquees 'SRC_ONLY' ne sont pas recopiees						# SRC_ONLY
																			# SRC_ONLY
CORE	 =	Makefile
# $(CXX) est le compilateur C++ par defaut, mais les options doivent etre specifiees
#        soit dans l'environnement (export CXXFLAGS='.........') soit dans le Makefile
CXXFLAGS =	-Wall


help:
	@echo
	@echo "make [help]   : cette page d'aide"
	@echo "make all      : compile tous les programmes de test"
	@echo "make Polygone :     \"   Polygone qui teste la classe eponyme"
	@echo "make Triangle :     \"   Triangle        \"             \""
	@echo "make Rectangle:     \"   Rectangle       \"             \""
	@echo "make Carre    :     \"   Carre           \"             \""
	@echo "make cleanrep : nettoie ce repertoire"
	@echo "make version  : numero de version de '$(CXX)' (options de compilation: >$(CXXFLAGS)<)"
	@echo
	@echo "make home     : cree le repertoire 'Polygone' du participant"	# SRC_ONLY
	@echo                                                                   # SRC_ONLY


all: Polygone Triangle Rectangle Carre TypeId DynCast


Polygone.cpp: Polygone.cpp.1  Polygone.cpp.2 Polygone.cpp.3 $(CORE)			# SRC_ONLY
	@echo  >./Polygone.cpp "// Fichier cree automatiquement par 'make'"		# SRC_ONLY
	@echo >>./Polygone.cpp													# SRC_ONLY
	@echo >>./Polygone.cpp "#include <iostream>"							# SRC_ONLY
	@echo >>./Polygone.cpp "#include \"Polygone.h\""						# SRC_ONLY
	@echo >>./Polygone.cpp "using namespace std ;"							# SRC_ONLY
	@echo >>./Polygone.cpp													# SRC_ONLY
	@cat ./Polygone.cpp.* | grep -v '^// *[fF]i' >>./Polygone.cpp			# SRC_ONLY
	@echo >>./Polygone.cpp													# SRC_ONLY
	@echo >>./Polygone.cpp "// Fin du fichier genere automatiquement"		# SRC_ONLY
	@																		# SRC_ONLY
	@																		# SRC_ONLY
%.o: %.cpp %.h $(CORE)
	$(CXX) $(CXXFLAGS) $*.cpp -c -o $*.o


%.o: %.cpp $(CORE)
	$(CXX) $(CXXFLAGS) $*.cpp -c -o $*.o


Polygone : Polygone.o Polygone.h $(CORE) Test-Polygone.o
	$(CXX) Polygone.o -o Polygone Test-Polygone.o


Triangle : Triangle.o Triangle.h $(CORE) Test-Triangle.o Polygone.o
	$(CXX) Triangle.o -o Triangle Test-Triangle.o Polygone.o


Rectangle : Rectangle.o Rectangle.h $(CORE) Test-Rectangle.o Polygone.o
	$(CXX) Rectangle.o -o Rectangle Test-Rectangle.o Polygone.o


Carre : Carre.o Carre.h $(CORE) Test-Carre.o Polygone.h Rectangle.o Polygone.o
	$(CXX) Carre.o -o Carre Test-Carre.o Polygone.o Rectangle.o


TypeId : TypeId.o Carre.h $(CORE) Rectangle.o Carre.o Triangle.o Polygone.o
	$(CXX) TypeId.o -o TypeId Carre.o Polygone.o Rectangle.o Triangle.o 


DynCast : DynCast.o Carre.h $(CORE) Rectangle.o Carre.o Triangle.o Polygone.o
	$(CXX) DynCast.o -o DynCast Carre.o Polygone.o Rectangle.o Triangle.o 


cleanrep:
	@rm -f *.o ? Polygone Triangle Rectangle Carre TypeId DynCast *~
	@rm -f Polygone.cpp											# SRC_ONLY


home: Polygone.cpp												# SRC_ONLY
	@rm -rf ../../Polygone										# SRC_ONLY
	@mkdir -m755 ../../Polygone 2>/dev/null						# SRC_ONLY
	@cp *.cpp ../../Polygone			 						# SRC_ONLY
	@rm -f Polygone.cpp											# SRC_ONLY
	@cp *.h ../../Polygone										# SRC_ONLY
	@echo "# Genere par :" >../../Polygone/Makefile				# SRC_ONLY
	@fgrep -v 'SRC_ONLY' <./Makefile >>../../Polygone/Makefile	# SRC_ONLY
	@															# SRC_ONLY
	@															# SRC_ONLY
version:
	@$(CXX) --version | head -1

# Fin de './Exemples/Polygone/Makefile'
