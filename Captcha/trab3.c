#include <stdio.h>
#include <stdlib.h>
#include <_lib_.h>

int main(void){
	FILE *file;
	int **matriz_captcha;
	int altura, largura;
	file = createFile();
	imageSize(file, &largura, &altura);
	matriz_captcha = readImage(file, largura, altura);
	medianFilter(matriz_captcha, largura, altura);
	return SUCCESS;
}
