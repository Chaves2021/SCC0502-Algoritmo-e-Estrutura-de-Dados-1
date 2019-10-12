CC=gcc
BINARY=./bin/trab
INCLUDES=./includes/
SRC=./src/_lib_.c ./src/trab.c
OPTIONS=-Wall -g
TEST=casos/3.in
LIBS=

all:
	@$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC)
run:
	@$(BINARY)
debug:
	@$(CC) $(OPTIONS) $(SRC) -I$(INCLUDES) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY)
