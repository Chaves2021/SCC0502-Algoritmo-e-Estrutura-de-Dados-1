CC=gcc
BINARY=./bin/trab0
INCLUDES=./includes/
SRC=./src/array_List.c ./src/trab0.c
OPTIONS=-Wall -g
LIBS=

all:
	@$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC)
run:
	@./bin/trab0
debug:
	@$(CC) $(OPTIONS) $(SRC) -I$(INCLUDES) -o $(BINARY)
	@valgrind --leak-check=yes ./bin/trab0
