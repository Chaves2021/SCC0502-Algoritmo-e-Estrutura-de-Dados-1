all:
	@gcc trab3.c _lib_.c -I. -o trab3
run:
	@./trab3

debug:
	@gcc -Wall -g trab3.c _lib_.c -I. -o trab3
	@valgrind --leak-check=yes ./trab3
