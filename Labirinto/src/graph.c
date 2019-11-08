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

//Funcao para printar a stack
//Ela fere o TAD, porem tive dificuldades em criar uma funcao copy_stack sem alterar a original
int *make_exit(STACK *stack){
	if(!stack) return (int *) INVALID_STACK;
	STACK_ELEMENT **p;
	p = &(stack->top);
	int *exit = (int *) malloc(stack->counter * sizeof(int));
	int counter = 1;
	while(*p){
		exit[stack->counter - counter] = (*p)->elem;
		p = &((*p)->next);
		counter++;
	}
	return exit;
}

int **exits(GRAPH *graph){
	STACK *stack;
	int **exit = NULL;
	int i;
	//Flag para sinalizar se ja cheguei na maior profundidade possivel
	int final = FALSE;
	//O counter_0 sera incrementado quando uma saida for achada, ele representa quantos paths de saida existem
	int counter_0 = 0;
	//Variavel para guardar tamanho maximo da saida
	//Queria usar o stack->counter mas ele eh decrementado a cada pop na stack :(
	stack = create_stack();
	exit = (int **) realloc(exit, 1 * sizeof(int));

	//TODO Soh consigo printar o primeiro caminho, pintar as arestas esta atrapalhando 
	push_stack_elem(stack, graph->start_index);
	graph->graph_elem[graph->start_index - 1]->isPassed = TRUE;
	//Enquanto tiver elementos na pilha
	while(stack->counter){
		if(graph->graph_elem[show_stack_top(stack) - 1]->isExit && final){
			//Escrevendo indices no vetor de saida
			exit[counter_0] = make_exit(stack);
			//Aumentando o tamanho do vetor de exit, falando que tem mais um path de saida
			counter_0++;
			exit = (int **) realloc(exit, (counter_0 + 1) * sizeof(int));
			for(i = 0; i < graph->vertices && stack->counter && final; i++){ 
				if(graph->adj[show_stack_top(stack)][i] && !graph->graph_elem[i]->isPassed){
					push_stack_elem(stack, i + 1);
					graph->graph_elem[i]->isPassed = TRUE;
					final = FALSE;
				}
				else if(i == (graph->vertices - 1)){
					pop_stack_elem(stack);
					i = 0;
				}
			}
		}
		//Caso tenha chegado no final mas seja um beco sem saida
		else if(!graph->graph_elem[show_stack_top(stack) - 1]->isExit && final){ 
			pop_stack_elem(stack);
		}
		//Caso nao tenha chegado ate o final daquela parte do grafo, avance no grafo
		else{
			for(i = 0; i < graph->vertices && !final; i++){
				if(graph->adj[show_stack_top(stack) - 1][i] && !graph->graph_elem[i]->isPassed){
					graph->graph_elem[i]->isPassed = TRUE;
					push_stack_elem(stack, i + 1);
					i = 0;
				}
			}	
			//Se chegou aqui, eh pq nao tem mais para onde ir
			final = TRUE;
		}
	}

	return exit;
}
