# Genere par :
# Fichier './Exemples/Polygone/Makefile'

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


all: Polygone Triangle Rectangle Carre TypeId DynCast


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


version:
	@$(CXX) --version | head -1

# Fin de './Exemples/Polygone/Makefile'
