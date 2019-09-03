#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <_lib_.h>

//Funcao para alocar matriz de int
//feita para evitar codigo macarronico
int **alocMatrix(int largura, int altura){
	int **matriz;
	int j;
	matriz = (int **) malloc(altura * sizeof(int *));
	if(!matriz)
		return ALOCATION_ERROR;
	for(j = 0; j < largura; j++){
		matriz[j] = (int *) malloc(largura * sizeof(int));
		if(!matriz[j])
			return ALOCATION_ERROR;
	}
	return matriz;
}

//Funcao para alocar string dinamicante
//feita para evitar codigo macarronico
char *alocString(){
	char *string;
	string = (string *) calloc(30, sizeof(char));
	return string;
}

//Funcao para ponteiro do tipo file apontar para o arquivo para sua posterior leitura
FILE *createFile(){
	FILE *file;
	char *arquivo;
	arquivo = declararString();
	if(!arquivo)
		return ALOCATION_ERROR;

	scanf(" %s", arquivo);
	file = fopen(arquivo, "r");

	//ATENCAO!!!!
	//ONDE DEIXAR ISSO??????
	//IGNORANDO O P2 DO ARQUIVO
	fscanf(file, "%*c %*c");

	free(arquivo);
	return file;
}

//Funcao para armazenar altura e largura
//O tom maximo de cinza eh ignorado ja que todos os captchas assumem valor 1 como maximo
void imageSize(FILE *file, int *largura, int *altura){
	fscanf(file, "%d %d", &largura, &altura);
	fscanf(file, "%*d");
}

//Funcao para ler o captcha e armazenar seus valores
int **readImage(FILE *file, int largura, int altura){
	int i, j;
	int **matriz_captcha;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			fscanf(arquivo, "%d", &matriz_captcha[i][j]);
		}
	}
	return matriz_captcha;
}
