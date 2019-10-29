#ifndef _GRAPH_H_
#define _GRAPH_H_
struct graph_elem{
	float x, y;
	int isCam;
	int isExit; 
	int verify; //Boolean para verificar se caminho ja foi feito ou nao
	int connections; //Numero de conexoes que esse vertice tem
	struct graph_elem **next; //Ponteiro duplo pois pode haver mais de um vertice conectado a outro
				  //Conexoes ordenadas por ordem numerica
}
typedef struct graph_elem GRAPH_ELEM;

struct graph{
	GRAPH_ELEM *first;
	int vertices; //os vertices sao os numeros de pontos
	int **adj; //se eh um caminho, o valor da matriz eh 1, se nao eh 0
	int paths; //numero de caminhos
}
typedef struct graph GRAPH;


#endif
