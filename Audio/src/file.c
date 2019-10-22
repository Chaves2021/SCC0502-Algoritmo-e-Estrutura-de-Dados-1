#include <stdlib.h>
#include <stdio.h>
#include <file.h>

#define ENTER 10

//Le todo o arquivo e grava em um vetor
void *ler_arquivo(FILE* arquivo, TYPE opt, int *vecSize){
	void *vec = NULL;
	int type;
	switch(opt){
		case CHAR:
		case UNSIGNED_CHAR:
			type = sizeof(char);
			break;
		case INT:
			type = sizeof(int);
			break;
		case DOUBLE:
			type = sizeof(double);
			break;
	}

	fseek(arquivo, 0, SEEK_END);
	*vecSize = ftell(arquivo);
	fseek(arquivo, 0, SEEK_SET);

	vec = malloc(type*(*vecSize));
	fread(vec, type, *vecSize, arquivo);

	return vec;
}
