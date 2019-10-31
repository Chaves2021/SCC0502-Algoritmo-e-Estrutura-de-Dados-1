#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <stack.h>
#include <math.h>
#include <defines.h>

int main(void){
	int np; //Numero de pontos
	int nc; //Numero de camaras
	int ns; //Numero de segmentos
	int s_in, s_out; //Quais pontos estao ligados, o de entrada e saida
	int start_index;
	float x, y;
	int index;
	int isExit;
	GRAPH *graph;

	scanf("%d", &np);
	graph->adj = (int **) malloc(np * sizeof(int *));
	graph->vertices = np;
	graph->graph_elem = (GRAPH_ELEM **) malloc(np * sizeof(GRAPH_ELEM *));

	//Armazenando todos os pontos
	for(i = 0; i < np; i++){
		graph->adj[i] = (int *) calloc(np, sizeof(int));
		graph->graph_elem[i] = (GRAPH_ELEM *) calloc(1, sizeof(GRAPH_ELEM));
		scanf("%f", &x);
		scanf("%f", &y);
		graph->graph_elem[i]->x = x;
		graph->graph_elem[i]->y = y;
	}

	//Armazenando todas as camaras
	scanf("%d", &nc);
	if(nc > np) return INVALID_CAM_NUMBER;
	for (i = 0; i < nc; i++){
		scanf("%d", &index);
		if(index > np) return INVALID_INDEX;
		graph->graph_elem[index]->isCam = TRUE;
		scanf("%d", &isExit);
		if(isExit) graph->graph_elem[index]->isExit = TRUE;
		else graph->graph_elem[index]->isExit = FALSE;

	}

	//Armazenando todos os paths
	scanf("%d", &ns);
	for (i = 0; i < ns; i++){
		scanf("%d %d", &s_in, &s_out);
		if(s_in > np || s_out > np || s_in == s_out) return INVALID_PATH;
		if(s_in < 0 || s_out < 0){
			graph->adj[s_in][s_out] = 0;
			graph->adj[s_out][s_in] = 0;
		}
		else{
			graph->adj[s_in][s_out] = 1;
			graph->adj[s_out][s_in] = 1;
		}
	}

	//Lendo indice da camara de inicio
	scanf("%d", &start_index);
	graph->start_index = start_index;

	return SUCCESS;
}
