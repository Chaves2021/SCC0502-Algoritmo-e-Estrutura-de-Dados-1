CC=gcc
BINARY=./bin/main
INCLUDES=./includes/
SRC=./src/sudoku.c ./src/main.c
OPTIONS=-Wall -g
TEST=casos/0.in

all:
	@$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC)
run:
	@$(BINARY) < $(TEST)
debug:
	@$(CC) $(OPTIONS) $(SRC) -I$(INCLUDES) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY) < $(TEST)
