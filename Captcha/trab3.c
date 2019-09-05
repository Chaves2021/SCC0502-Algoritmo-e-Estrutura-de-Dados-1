#include <stdio.h>
#include <stdlib.h>
#include <_lib_.h>

int main(void){
	FILE *file;
	int **matriz_captcha;
	int altura, largura;
	char *arquivo;
	arquivo = alocString();
	scanf(" %s", arquivo);
	file = createFile(arquivo);
	imageSize(file, &largura, &altura);
	matriz_captcha = readImage(file, largura, altura);
	medianFilter(matriz_captcha, largura, altura);
	/*for(int i = 0; i < altura; i++){
		printf("\n");
		for(int j = 0; j < largura; j++){
			printf("%d ", matriz_captcha[i][j]);
		}
	}*/
	compareNumber(matriz_captcha, largura, altura);
	return SUCCESS;
}
