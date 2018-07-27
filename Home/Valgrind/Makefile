#! /usr/bin/make -f

# CC			:= g++
CC			:= clang++
CXXFLAGS	:= -Wall
LDFLAGS		:= -Wall

test: valgrind
valgrind: Valgrind
	valgrind    --leak-check=full --show-leak-kinds=all ./Valgrind
#	valgrind -v --leak-check=full --show-leak-kinds=all ./Valgrind

Valgrind: Valgrind.cpp Makefile
	$(CC) -o Valgrind $(CXXFLAGS) $(LDFLAGS) Valgrind.cpp

versions:
	@valgrind --version | sed '1q'
	@gcc --version | sed '1q'
	@clang --version | sed '1q'

cleanrep: clean
clean:
	@rm -f ./Valgrind
	@chmod +x ./Makefile

# fin de fichier
