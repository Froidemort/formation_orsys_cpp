# Debut de Makefile - Email - Version 1.1

CC   = g++ -Wall
PRG  = Email
OBJ  = Test.o Email.o
CORE = Email.h Makefile

$(PRG): $(OBJ) $(CORE)
	$(CC) -o $(PRG) $(OBJ)

%.o: %.cpp $(CORE)
	$(CC) -c $<

test: $(PRG)
	@./$(PRG)
	@echo

cleanrep:
	@rm -f *.o $(PRG)

# Fin de Makefile
