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
		//Apenas checando se o caminho eh possivel, pois se nao ja esta setado como 0 por conta do malloc
		if(s_in > 0 && s_out > 0){
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

STACK *copy_stack(STACK *stack){
	if(!stack) return INVALID_STACK;
	STACK *stack_aux;

	return stack_aux;
}

int **exits(GRAPH *graph){
	STACK *stack;
	STACK *stack_aux;
	int **exit;
	//Flag para sinalizar se ja cheguei na maior profundidade possivel
	int final = FALSE;
	//O counter_0 sera incrementado quando uma saida for achada, ele representa quantos paths de saida existem
	int counter_0 = 0;
	//Variavel para guardar tamanho maximo da saida
	//Queria usar o stack->counter mas ele eh decrementado a cada pop na stack :(
	int aux;
	stack = create_stack();
	exit = (int **) realloc(exit, 1 * sizeof(int));

	//TODO A principio irei pintar as arestas, mas nao sei se isso pode me atrapalhar em alguns casos de teste
	//TODO Implementar a funcao copy_stack
	push_stack_elem(stack, graph->start_index);
	while(stack->counter){
		if(graph->graph_elem[show_stack_top(stack)]->isExit && final){
			stack_aux = copy_stack(stack);
			//Escrevendo indices no vetor de saida
			for(i = 0; i < stack->counter; i++){
				exit[counter_0] = (int *) malloc(stack->counter * sizeof(int));
				exit[counter_0][(stack->counter - 1) - i] = pop_stack_elem(stack_aux);
			}
			//Aumentando o tamanho do vetor de exit, falando que tem mais um path de saida
			counter_0++;
			exit = (int **) realloc(exit, counter_0 * sizeof(int));
			aux = stack->counter - 1;
			for(i = 0; i < graph->vertices && graph->counter; i++){ 
				if(stack->adj[show_stack_top(stack)][i] && !graph->graph_elem[i]->isPassed && final){
					push_stack_elem(stack, i);
					graph->graph_elem[i]->isPassed = TRUE;
					final = FALSE;
				}
				else if(i == (graph->vertices - 1)){
					pop_stack_elem(stack);
					i = 0;
				}
			}
		}
		//Caso nao tenha chegado ate o final daquela parte do grafo, avance no grafo
		else{
			for(i = 0; i < graph->vertices && !final; i++){
				if(stack->adj[show_stack_top(stack)][i] && !graph->graph_elem[i]->isPassed){
					graph->graph_elem[i]->isPassed = TRUE;
					push_stack_elem(stack, i);
					i = 0;
				}
				else final = TRUE;
			}	
		}
	}

	return SUCCESS;
}
