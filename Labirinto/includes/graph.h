#ifndef _GRAPH_H_
#define _GRAPH_H_

//Graph elem sera um vetor que armazenara uma informacao de cada ponto
//Sera a informacao dos vertices do grafo, porem sem estar linkado 
struct graph_elem{
	float x, y;
	int isCam;
	int isExit; 
	int connections; //Numero de conexoes que esse vertice tem
}
typedef struct graph_elem GRAPH_ELEM;

//Graph sera um unico elemento com as infos do labirinto
struct graph{
	int start_index; //indice da camera de inicio
	int vertices; //os vertices sao os numeros de pontos
	int cams; //numero de camaras
	int paths; //numero de segmentos
	int **adj; //se eh um caminho, o valor da matriz eh 1, se nao eh 0
	GRAPH_ELEM **graph_elem;
}
typedef struct graph GRAPH;

//TODO Mudar main para modularizar melhor o codigo
//GRAPH *create_graph();
int **paths(GRAPH *);
int free_graph(GRAPH *);
#endif
