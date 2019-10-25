CC=gcc
BINARY=./bin/trab_final
INCLUDES=./includes/
SRC=./src/complex_sparse_cube.c ./src/main.c
OPTIONS=-Wall -g
TEST=casos/1.in

all:
	@$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC)
run:
	@$(BINARY)
debug:
	@$(CC) $(OPTIONS) $(SRC) -I$(INCLUDES) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY)
