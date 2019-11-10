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
	graph->valid_paths = (int **) malloc(np * sizeof(int *));
	graph->vertices = np;
	graph->graph_elem = (GRAPH_ELEM **) malloc(np * sizeof(GRAPH_ELEM *));

	//Armazenando todos os pontos
	for(i = 0; i < np; i++){
		graph->adj[i] = (int *) calloc(np, sizeof(int));
		graph->valid_paths[i] = (int *) calloc(np, sizeof(int));
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
		//Apenas checando se o caminho eh possivel, pois se nao ja esta setado como 0 por conta do calloc
		if(s_in > 0 && s_out > 0){
			graph->adj[s_in - 1][s_out - 1] = 1;
			graph->adj[s_out - 1][s_in - 1] = 1;

			graph->valid_paths[s_in - 1][s_out - 1] = 1;
			graph->valid_paths[s_out - 1][s_in - 1] = 1;

			graph->graph_elem[s_in - 1]->connections += 1;
			graph->graph_elem[s_out - 1]->connections += 1;
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
int *make_exit(STACK *stack, int *counter_points){
	if(!stack) return (int *) INVALID_STACK;
	STACK_ELEMENT **p;
	p = &stack->top;
	int *exit = (int *) calloc(stack->counter,  sizeof(int));
	int counter = 1;
	*counter_points = 0;
	while(*p){
		exit[stack->counter - counter] = (*p)->elem;
		p = &((*p)->next);
		counter++;
	}
	//Como counter ja comeca com 1, ele sempre precisara ser decrementado em 1
	(*counter_points) = counter - 1;
	return exit;
}

//Calcular a distancia euclidiana entre 2 pontos para saber o tamanho do segmento
int euclidian_distance(int x1, int y1, int x2, int y2){
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

float geodesic_distance(GRAPH *graph, int *exit, int counter_points){
	float dist = 0;
	float x1, x2, y1, y2;
	int i;
	for(i = 0; i < counter_points - 1; i++){
		x1 = graph->graph_elem[exit[i]]->x;
		y1 = graph->graph_elem[exit[i]]->y;
		x2 = graph->graph_elem[exit[i + 1]]->x;
		y2 = graph->graph_elem[exit[i + 1]]->y;
		dist += euclidian_distance(x1, y1, x2, y2);
	}

	return dist;
}

//Funcao para formatar a saida esperada no run.codes
/*
int build_answer(GRAPH *graph, int **exit, int *counter_points, int counter_0){
	//Variavel auxiliar para saber quais paths ja foram printados
	int *isPrinted;
	//Variavel para saber se todos os paths foram printados
	int print_counter = counter_0;
	isPrinted = (int *) calloc(counter_0, sizeof(int));
	//Variavel para saber a ordem dos indices do vetor exit a serem printados
	int *sorted_index;
	sorted_index = (int *) malloc(counter_0 * sizeof(int));
	//Variavel para saber a distancia da origem ate a saida de cada path
	float *dist;
	dist = (float *) calloc(counter_0, sizeof(float));
	//Variavel auxiliar para guardar valor temporariamente
	int aux;
	int i, j;

	//Inicializando vetor com todos os indices do vetor exit
	for(i = 0; i < counter_0; i++){
		sorted_index[i] = i;
	}

	//Calculando a distancia geodesica de cada path
	for(i = 0; i < counter_0; i++){
		dist[i] = geodesic_distance(graph, exit[i], counter_points[i]);
	}

	//Ordenando pela distancia geodesica dos pontos
	for(i = 0; i < counter_0 - 1; i++){
		for(j = i + 1; j < counter_0; j++){
			if(dist[sorted_index[i]] > dist[sorted_index[j]]){
				aux = sorted_index[i];
				sorted_index[i] = sorted_index[j];
				sorted_index[j] = aux;
			}
		}
	}
	//Ordenando por menor numero de pontos caso a distancia geodesica seja a mesma
	for(i = 0; i < counter_0 - 1; i++){
		for(j = i + 1; j < counter_0; j++){
			if(dist[sorted_index[i]] == dist[sorted_index[j]] 
					&& counter_points[sorted_index[i]] > counter_points[sorted_index[j]]){
				aux = sorted_index[i];
				sorted_index[i] = sorted_index[j];
				sorted_index[j] = aux;
			}
		}
	}

	//Ordenando por ordem crescente de pontos caso a distancia seja a mesma e tenham o mesmo num de pontos
	for(i = 0; i < counter_0 - 1; i++){
		for(j = i + 1; j < counter_0; j++){
			if(dist[sorted_index[i]] == dist[sorted_index[j]] 
					&& counter_points[sorted_index[i]] == counter_points[sorted_index[j]]){

			}
		}
	}

	return SUCCESS;
}
*/

//Poderia ter refatorado o codigo, trechos repetidos porem nao tive tempo :(
int **exits(GRAPH *graph){
	STACK *stack;
	int **exit = NULL;
	int i;
	int final = FALSE;
	//Flag para saber se preciso fazer uma nova checagem se o vertice eh saida ou nao
	int new_check = FALSE;
	//O counter_0 sera incrementado quando uma saida for achada, ele representa quantos paths de saida existem
	int counter_0 = 0;
	//Variavel para contar quantos pontos tem cada saida
	int *counter_points = NULL;
	//Queria usar o stack->counter mas ele eh decrementado a cada pop na stack :(
	stack = create_stack();
	exit = (int **) realloc(exit, 1 * sizeof(int *));
	counter_points = (int *) realloc(counter_points, 1 * sizeof(int));

	push_stack_elem(stack, graph->start_index);
	graph->graph_elem[graph->start_index - 1]->isActive = TRUE;
	//Enquanto tiver elementos na pilha
	while(stack->counter){
		if(!graph->graph_elem[show_stack_top(stack) - 1]->isExit && final){
			//Se nao existem paths disponiveis, entao voltar
			graph->graph_elem[show_stack_top(stack) - 1]->isActive = FALSE;
			final = FALSE;
			pop_stack_elem(stack);
		}
		else if(graph->graph_elem[show_stack_top(stack) - 1]->isExit && final){
			new_check = FALSE;
			//Escrevendo indices no vetor de saida
			exit[counter_0] = make_exit(stack, &(counter_points[counter_0]));
			//Aumentando o tamanho do vetor de exit, falando que tem mais um path de saida
			counter_0++;
			exit = (int **) realloc(exit, (counter_0 + 1) * sizeof(int));
			counter_points = (int *) realloc(counter_points, (counter_0 + 1) * sizeof(int));
			for(i = 0; i < graph->vertices && !new_check; i++)
				if(graph->valid_paths[show_stack_top(stack) - 1][i] && !graph->graph_elem[i]->isActive){
					graph->graph_elem[i]->isActive = TRUE;
					graph->valid_paths[show_stack_top(stack) - 1][i] = 0;
					push_stack_elem(stack, i + 1);
					new_check = TRUE;
				}
			//Se nao existem paths disponiveis, entao voltar
			if(!new_check){
				graph->graph_elem[show_stack_top(stack) - 1]->isActive = FALSE;
				final = FALSE;
				pop_stack_elem(stack);
			}
		}
		//Ainda nao cheguei no final
		else{
			new_check = FALSE;
			for(i = 0; i < graph->vertices && !new_check; i++)
				if(graph->valid_paths[show_stack_top(stack) - 1][i] && !graph->graph_elem[i]->isActive){
					graph->graph_elem[i]->isActive = TRUE;
					graph->valid_paths[show_stack_top(stack) - 1][i] = 0;
					push_stack_elem(stack, i + 1);
					new_check = TRUE;
				}
			//Se nao existem paths disponiveis, entao cheguei no final
			if(!new_check){
				final = TRUE;
			}
		}
	}
	return exit;
}
