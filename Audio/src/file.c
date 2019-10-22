#include <stdlib.h>
#include <stdio.h>
#include <file.h>

#define ENTER 10

//Le todo o arquivo e grava em um vetor
void *ler_arquivo(FILE* arquivo, int *tamanho){
	void *vetor = NULL;
	fseek(arquivo, 0, SEEK_END);
	*tamanho = ftell(arquivo);
	fseek(arquivo, 0, SEEK_SET);
	vetor = malloc((*tamanho) * sizeof(char));
	fread(vetor, sizeof(char), *tamanho, arquivo);

	return vetor;
}
