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
	//O counter_0 sera incrementado quando uma saida for achada, ele representa quantos paths de saida existem
	int counter_0 = 1;
	//Variavel para guardar tamanho maximo da saida
	//Queria usar o stack->counter mas ele eh decrementado a cada pop na stack :(
	int aux;
	stack = create_stack();
	exit = (int **) realloc(exit, counter_0 * sizeof(int));
	exit[0] = (int *) realloc(exit, 1 * sizeof(int));
	counter_0++;

	//TODO Implementar uma DFS alterada
	//TODO Aparentemente nao vou pintar as arestas, mas penso que quando meu start_index nao for o inicio, talvez precise
	//TODO Nao sei se a funcao de printar a stack fere o TAD, irei perguntar hoje a noite na aula
	push_stack_elem(stack, graph->start_index);
	while(stack->counter){
		if(graph->graph_elem[show_stack_top(stack)]->isExit){
			aux = stack->counter - 1;
			for(i = 0; i < stack->counter; i++){
				exit[counter_0][aux - i] = pop_stack_elem(stack);
			}
		}
	}

	return SUCCESS;
}
