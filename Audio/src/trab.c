#include <stdio.h>
#include <stdlib.h>
#include <file.h>
#include <math.h>
#include <complex.h>
#include <fourier.h>

#define SIZE UNSIGNED_CHAR

int main(int argc, char *argv[]){
	char arquivo[11];
	unsigned char *valor;
	int c, tamanho = 0, i;
	complex double *coeficiente;
	double *mag;
	int *pos;
	FILE *fp;
	scanf(" %s", arquivo);
	fp = fopen(arquivo, "rb");
	scanf("%d", &c);
	valor = (unsigned char *) ler_arquivo(fp, SIZE, &tamanho);
	fclose(fp);
	coeficiente = dft(valor, tamanho);
	pos = (int *) malloc(sizeof(int)*(1+(tamanho/2)));
	for(i = 0; i <= tamanho/2; i++) pos[i] = i;
	mag = ordena_coeficiente(coeficiente, pos, tamanho/2);
	printf("%d\n", tamanho);
	for(i = 0; mag[i] > 0.1; i++);
	printf("%d\n", i);
	for(i = 0; i < c; i++) printf("%d ", (int) mag[i]);
	printf("\n");
	zera_coeficiente(coeficiente, pos, c, tamanho/2);
	free(mag);
	free(pos);
	free(valor);
	valor = dft_inversa(coeficiente, tamanho);
	for(i = 0; i < tamanho; i++) printf("%d\n", valor[i]);
	free(valor);
	free(coeficiente);
	return 0;

}
