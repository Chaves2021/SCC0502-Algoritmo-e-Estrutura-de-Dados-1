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
	//Dando free para que compilador nao reclame de variavel nao utilizada
	free(exit);

	//O usuario deveria chamar a funcao build_answer para formatar a resposta, porem nao tive tempo de implementa-la
	//Queria que o usuario chamasse a funcao build_answer ao inves dela ser executada dentro da funcao exits
	//Porem nao tive tempo de refaze-la, entao as variaveis counter_points e counter_0 so sao acessadas dentro da funcao exits
	//Pensei em fazer uma struct de saidas para armazenas essas variaveis dentro do grafo, porem novamente sem tempo :(
	//build_answer(graph, exit, counter_points, counter_0);
	return SUCCESS;
}
