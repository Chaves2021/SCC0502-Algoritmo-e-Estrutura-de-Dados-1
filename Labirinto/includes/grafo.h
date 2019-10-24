#ifndef _GRAFO_H_
#define _GRAFO_H_
struct grafo_elem{
	float x, y;
	int 
}
typedef struct grafo_elem GRAFO_ELEM;

struct grafo{
	GRAFO_ELEM *origem;
	int vertices; //os vertices sao os numeros de pontos
	int **adj; //se eh um caminho, o valor da matriz eh 1, se nao eh 0
	int arcos; //numero de caminhos
}
typedef struct grafo GRAFO;
#endif
