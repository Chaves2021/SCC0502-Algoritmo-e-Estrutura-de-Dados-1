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
	int start_index;
	GRAPH *graph;
	int **exit;

	graph = create_graph();
	scanf("%d", &np);
	save_points(graph, np);

	//Armazenando todas as camaras
	scanf("%d", &nc);
	save_cams(graph, nc, np);

	//Armazenando todos os paths
	scanf("%d", &ns);
	save_paths(graph, ns, np);

	//Lendo indice da camara de inicio
	scanf("%d", &start_index);
	set_start_index(graph, start_index, np);

	//Definindo todas as saidas do labirinto
	exit = exits(graph);
	
	return SUCCESS;
}
