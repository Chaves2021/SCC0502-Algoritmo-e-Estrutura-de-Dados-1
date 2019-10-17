CC=gcc
BINARY=./bin/trab_final
INCLUDES=./includes/
SRC=./src/fourier.c ./src/trab_final.c
OPTIONS=-Wall -g

all:
	@$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC)
run:
	@$(BINARY)
debug:
	@$(CC) $(OPTIONS) $(SRC) -I$(INCLUDES) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY)
