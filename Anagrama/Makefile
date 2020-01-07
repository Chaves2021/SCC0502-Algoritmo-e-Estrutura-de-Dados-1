CC=gcc
BINARY=./bin/trab
INCLUDES=./includes/
SRC=./src/hash.c ./src/main.c
OPTIONS=-Wall -g -lm
TEST=casos/1.in

all:
	@$(CC) $(SRC) -o $(BINARY) -I$(INCLUDES) $(OPTIONS)
run:
	@$(BINARY)
debug:
	@$(CC) $(OPTIONS) $(SRC) -I$(INCLUDES) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY) < $(TEST)
