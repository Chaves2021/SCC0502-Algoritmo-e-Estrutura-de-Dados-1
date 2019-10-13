CC=gcc
BINARY=./bin/trab_final
INCLUDES=./includes/
SRC=./src/array_List.c ./src/trab_final.c
OPTIONS=-Wall -g
TEST=casos/1.in

all:
	@$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC)
run:
	@$(BINARY) < teste.in
debug:
	@$(CC) $(OPTIONS) $(SRC) -I$(INCLUDES) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY)
