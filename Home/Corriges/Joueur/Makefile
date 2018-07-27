# Fichier './Joueur/Makefile'             -    4 liens physiques
# Fichier './Greed/Makefile'
# Fichier './Corriges/Joueur/Makefile'    -    Version avec tableau de Joueur*
# Fichier './Corriges/Greed/Makefile'     -    Version avec std::vector<>

CXX   := g++ -Wall
PRG   := Greed
OBJ   := ../Joueur/Joueur.o ../Tour/Tour.o ../Rand/Rand.o ./Greed.o
CORE  := Makefile ../De/De.h ../Tour/Tour.h ../Joueur/Joueur.h ../Rand/Rand.h

help:
	@printf "\n"
	@printf "make %-10s : %s\n" "[help]" "Cette page d'aide"
	@printf "make %-10s : %s\n" "test" "Compile et teste le projet"
	@printf "make %-10s : %s\n" "compile" "Compilation seule"
	@printf "make %-10s : %s\n" "$(PRG)"  "        id."
	@printf "make %-10s : %s\n" "cleanrep"  "Nettoie le repertoire du projet"
	@printf "\n"

$(PRG): $(OBJ)
	$(CXX) -o $(PRG) $(OBJ)

test: $(PRG)
	@./$(PRG)
	@echo

cleanrep:
	@rm -f *.o $(PRG) *~ $(OBJ)

%.o: %.cpp $(CORE)
	$(CXX) -c -o $*.o $<

# Fin de Makefile
