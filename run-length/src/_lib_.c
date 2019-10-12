#include <stdio.h>
#include <stdlib.h>
#include <_lib_.h>
#include <string.h>
#include <defines.h>

Arquivo *aloca_arq(char *numero_magico, int valor_max,  int largura, int altura){
	Arquivo *arq;
	arq = (Arquivo *) malloc(1 * sizeof(Arquivo));
	int **matriz_p2;
	char **matriz_p8;
	int i;
		matriz_p2 = (int **) malloc(altura * 5 * sizeof(int *));
		for(i = 0; i < altura; i++)
			matriz_p2[i] = (int *) malloc(largura * 5 * sizeof(int));
		arq->matriz_p2 = matriz_p2;
		matriz_p8 = (char **) malloc(altura * 8 * sizeof(char *));
		for(i = 0; i < altura; i++)
			matriz_p8[i] = (char *) malloc(largura * 8 * sizeof(char));
		arq->matriz_p8 = matriz_p8;
	arq->numero_magico = numero_magico;
	arq->valor_max = valor_max;
	arq->altura = altura;
	arq->largura = largura;
	return arq;
}

int p2_to_p8(Arquivo *arq){
	int i, j, igual = 0;
	int cont = 0;
	char *aux;
	aux = (char *) calloc(100, sizeof(char));
	for(i = 0; i < arq->altura; i++){
		for(j = 0; j < arq->largura; j++){
			scanf("%d", &(arq->matriz_p2[i][j]));
		}
	}
	for(i = 0; i < arq->altura; i++){
		for(j = 0; j < arq->largura; j++){
			if(arq->matriz_p2[i][j] == arq->matriz_p2[i][j + 1] && arq->matriz_p2[i][j + 1] == arq->matriz_p2[i][j + 2]){
				igual = 1;
				cont = 3;
				while(igual && j + cont - 1 < arq->largura){
					if(arq->matriz_p2[i][j] == arq->matriz_p2[i][j+cont]){
						cont ++;
					}
					else igual = 0;
				}
				sprintf(aux, "@ %d %d ", arq->matriz_p2[i][j], cont - 1);
				strcat(arq->matriz_p8[i], aux); 
				igual = 0;
				memset(aux, 0, 100);
				j += cont - 1;
				cont = 0;
			}
			else{
				sprintf(aux, "%d ", arq->matriz_p2[i][j]);
				strcat(arq->matriz_p8[i], aux); 
				memset(aux, 0, 100);
			}
		}
	}

	return SUCCESS;
}

int p8_to_p2(Arquivo *arq){
	char *token;
	char *rest;
	int flag = 0, flag1 = 0;
	int valor, tamanho;
	int i, indice = 0;
	int cont;
	for(i = 0; i < arq->altura; i++){
		scanf(" %[^\n]%*c", arq->matriz_p8[i]);
	}
	for(i = 0; i < arq->altura; i++){
		rest = arq->matriz_p8[i]; 
		indice = 0;
		while ((token = strtok_r(rest, " ", &rest))){ 
			if(flag1){
				tamanho = atoi(token);
				for(cont = 0; cont < tamanho; cont++, indice++)
					arq->matriz_p2[i][indice] = valor;
				flag = flag1 = 0;
			}
			else if(flag){
				valor = atoi(token); 
				flag1 = 1;
			}
			else if(strcmp("@",token) == 0){
				flag = 1;
			}
			else{
				valor = atoi(token);
				arq->matriz_p2[i][indice] = valor;
				indice++;
			}
		}
	}


	return SUCCESS;
}

void print_matriz(Arquivo *arq){
	int i, j;
	if(strcmp(arq->numero_magico,"P2") == 0){
		printf("P8\n");
		printf("%d %d\n", arq->largura, arq->altura);
		printf("%d\n", arq->valor_max);
		for(i = 0; i < arq->altura; i++)
				printf("%s\n", arq->matriz_p8[i]);
	}

	else if(strcmp(arq->numero_magico, "P8") == 0){
		printf("P2\n");
		printf("%d %d\n", arq->largura, arq->altura);
		printf("%d\n", arq->valor_max);
		for(i = 0; i < arq->altura; i++)
			for(j = 0; j < arq->largura; j++){
				if(j == arq->largura - 1) printf("%d\n", arq->matriz_p2[i][j]);
				else printf("%d ", arq->matriz_p2[i][j]);
			}
	}
}

int ler_input(Arquivo **arq){
	char *numero_magico;
	numero_magico = (char *) malloc(sizeof(char) * 9);
	int altura, largura;
	int valor_max;
	scanf(" %s", numero_magico);
	scanf("%d %d", &largura, &altura);
	scanf("%d", &valor_max);
	*arq = aloca_arq(numero_magico, valor_max, largura, altura);
	if(strcmp(numero_magico, "P8") == 0){
		p8_to_p2(*arq);
		print_matriz(*arq);
		return SUCCESS;
	}
	else if(strcmp(numero_magico, "P2") == 0){
		p2_to_p8(*arq);
		print_matriz(*arq);
		return SUCCESS;
	}

	return -1;
}

int free_matriz(){


	return SUCCESS;
}
