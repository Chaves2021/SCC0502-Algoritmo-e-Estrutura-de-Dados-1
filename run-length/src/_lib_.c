#include <stdio.h>
#include <stdlib.h>
#include <_lib_.h>
#include <string.h>

Arquivo *aloca_arq(char *numero_magico, int valor_max,  int largura, int altura){
	Arquivo *arq;
	arq = (Arquivo *) malloc(1 * sizeof(Arquivo));
	int **matriz;
	int i;
	if(strcmp(numero_magico, "P2")){
		matriz = (int **) malloc(altura * sizeof(int *));
		for(i = 0; i < altura; i++){
			matriz[i] = (int *) malloc(largura * sizeof(int));
		}
		arq->matriz_p2 = matriz;
	}
	else if(strcmp(numero_magico, "P8")){
		matriz = (char **) malloc(altura * sizeof(char *));
		for(i = 0; i < altura; i++){
			matriz[i] = (char *) malloc(largura * 3 * sizeof(char));
		}
		arq->matriz_p8 = matriz;
	}
	arq->altura = altura;
	arq->largura = largura;
}

int p2_to_p8(){


}

//TODO
//Implementar strtok para separar os numeros
int p8_to_p2(Arquivo *arq){
	char *aux;
	aux = (char *) calloc(4, sizeof(char));
	for(i = 0; i < arq->altura; i++){
		scanf(" %s", arq->matriz_p8[i]);
	}
	for(i = 0; i < arq->altura; i++){
		for(j = 0; j < arq->largura; j++){
		}
	}


}

int ler_input(Arquivo *arq){
	char *numero_magico;
	int altura, largura;
	int valor_max;
	scanf(" %s", numero_magico);
	scanf("%d %d", &largura, &altura);
	scanf("%d", valor_max);
	aloca_arq(numero_magico, valor_max, largura, altura);
	if(stcmp(numero_magico == "P8")){
		p8_to_p2(arq);
	}
	else if(stcmp(numero_magico == "P2")){
		p2_to_p8(arq);
	}

}

int free_matriz(){



}
