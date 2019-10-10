#ifndef _lib_
#define _lib_
struct Arquivo{
	char *numero_magico;
	int largura;
	int altura;
	int valor_max;
	int **matriz_p2;
	char **matriz_p8;
}
typedef struct Arquivo Arquivo;

int ler_input();
int **aloca_arq(int, int);
int p2_to_p8(Arquivo *);
int p8_to_p2(Arquivo *);
int free_matriz();

#endif
