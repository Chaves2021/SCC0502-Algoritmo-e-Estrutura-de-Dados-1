CC=gcc
BINARY=./bin/main
INCLUDES=./includes/
SRC=./src/stack.c ./src/graph.c ./src/main.c
OPTIONS=-Wall -g -lm
TEST=casos/8.in

all:
	@$(CC) $(OPTIONS) -o $(BINARY) -I$(INCLUDES) $(SRC)
run:
	@$(BINARY) < $(TEST)
debug:
	@$(CC) $(OPTIONS) $(SRC) -I$(INCLUDES) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY) < $(TEST)
