#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack.h>
#include <graph.h>
#include <defines.h>

GRAPH *create_graph(){
	GRAPH *graph;
	graph = (GRAPH *) malloc(sizeof(GRAPH));
	return graph;
}

int save_points(GRAPH *graph, int np){
	int i;
	float x, y;
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
	return SUCCESS;
}

int save_cams(GRAPH *graph, int nc, int np){
	int i;
	int index;
	int isExit;
	if(nc > np) return INVALID_CAM_NUMBER;
	graph->cams = np;
	for (i = 0; i < nc; i++){
		scanf("%d", &index);
		if(index > np) return INVALID_INDEX;
		graph->graph_elem[index - 1]->isCam = TRUE;
		scanf("%d", &isExit);
		if(isExit) graph->graph_elem[index - 1]->isExit = TRUE;
		else graph->graph_elem[index - 1]->isExit = FALSE;
	}
	return SUCCESS;
}

int save_paths(GRAPH *graph, int ns, int np){
	int i;
	int s_in, s_out; //Quais pontos estao ligados, o de entrada e saida
	graph->paths = ns;
	for (i = 0; i < ns; i++){
		scanf("%d %d", &s_in, &s_out);
		if(s_in > np || s_out > np || s_in == s_out) return INVALID_PATH;
		if(s_in < 0 || s_out < 0){
			graph->adj[abs(s_in) - 1][abs(s_out) - 1] = 0;
			graph->adj[abs(s_out) - 1][abs(s_in) - 1] = 0;
		}
		else{
			graph->adj[s_in - 1][s_out - 1] = 1;
			graph->adj[s_out - 1][s_in - 1] = 1;
		}
	}
	return SUCCESS;
}

int set_start_index(GRAPH *graph, int start_index, int np){
	if(start_index <= 0 || start_index > np) return INVALID_INDEX;
	graph->start_index = start_index;
	return SUCCESS;
}

int **exits(GRAPH *graph){
	STACK *stack;
	int **exit;
	int counter_0 = 1;
	int counter_1 = 1;
	stack = create_stack();
	exit = (int **) realloc(exit, counter_0 * sizeof(int*));
	exit[0] = (int *) realloc(exit, counter_1 * sizeof(int));


	return SUCCESS;
}
