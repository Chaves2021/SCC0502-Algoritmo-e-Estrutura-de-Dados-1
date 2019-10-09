CC=gcc
BINARY=./bin/trab4
INCLUDES=./includes/
SRC=./src/array_List.c ./src/trab4.c
OPTIONS=-Wall -g
LIBS=

all:
	@$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC)
run:
	@$(BINARY)
debug:
	@$(CC) $(OPTIONS) $(SRC) -I$(INCLUDES) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY)
