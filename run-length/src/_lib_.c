#include <stdio.h>
#include <stdlib.h>
#include <_lib_.h>
#include <string.h>

Arquivo *aloca_arq(char *numero_magico, int valor_max,  int largura, int altura){
	Arquivo *arq;
	arq = (Arquivo *) malloc(1 * sizeof(Arquivo));
	int **matriz;
	int i;
	if(strcmp(numero_magico, "p2")){
		matriz = (int **) malloc(altura * sizeof(int *));
		for(i = 0; i < altura; i++){
			matriz[i] = (int *) malloc(largura * sizeof(int));
		}
		arq->matriz_p2 = matriz;
	}
	else if(strcmp(numero_magico, "p8")){
		matriz = (int **) malloc(altura * sizeof(int *));
		for(i = 0; i < altura; i++){
			matriz[i] = (int *) malloc(largura * sizeof(int));
		}
		arq->matriz_p8 = matriz;
	}
	arq->altura = altura;
	arq->largura = largura;
	arq->matriz_p2 = matriz_p2;
}

int ler_input(Arquivo *arq){
	char *numero_magico;
	int altura, largura;
	int valor_max;
	scanf(" %s", numero_magico);
	scanf("%d %d", &largura, &altura);
	scanf("%d", valor_max);
	aloca_arq(numero_magico, valor_max, largura, altura);

}

int p2_to_p8(){


}

int p8_to_p2(){



}

int free_matriz(){



}
