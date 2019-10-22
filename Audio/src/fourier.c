#include <stdio.h>
#include <stdlib.h>
#include <file.h>
#include <math.h>
#include <complex.h>

complex double *dft(unsigned char *valor, int N){
	int k, t;
	double exp; //parte do expoente que sera elevado em e
	complex double *coeficiente;
	coeficiente = (complex double *) malloc((N / 2 + 1) * sizeof(complex double));
	complex double z; //resultado do somatorio
	for(k = 0; k <= N/2; k++){
		z = 0;
		for(t = 0; t < N; t++){
			exp = 2 * k * acos(-1) * t / N; //Tambem eh usado o arccos de -1 para ter o valor de pi
			z += cexp(-1 * I * exp) * valor[t];
		}
		if(k == 0)
			coeficiente[k] = (1.0 / N) * z;
		else
			coeficiente[k] = (2.0 / N) * z;
	}
	return coeficiente;
}

unsigned char *dft_inversa(complex double *coeficiente, int N){
	int k, t;
	double exp; //parte do expoente que sera elevado em e
	unsigned char *valor;
	valor = (unsigned char *) malloc((N + 1) * sizeof(unsigned char));
	complex double z; //resultado do somatorio
	for(k = 0; k <= N; k++){
		z = 0;
		for(t = 0; t <= N/2; t++){
			exp = 2 * k * acos(-1) * t / N; //Tambem eh usado o arccos de -1 para ter o valor de pi
			z += cexp(I * exp) * coeficiente[t];
		}
		valor[k] = (unsigned char) round(creal(z)); // Arredondando valor para cima quando parte decimal eh >= 5
	}
	return valor;
}

void troca(double *vetor, int pos0, int pos1){
	double aux;
	aux = vetor[pos0];
	vetor[pos0] = vetor[pos1];
	vetor[pos1] = aux;
}

double *ordena_coeficiente(complex double *coeficiente, int *pos, int N){
	int i, j, aux;
	double *mag = malloc(sizeof(double)*(N+1));
	for(i = 0; i <= N; i++)
		mag[i] = cabs(coeficiente[i]);
	for(i = 0; i <= N; i++){
		for(j = 1; j <= N-i; j++){
			if(mag[j] > mag[j-1]){
				troca(mag, j, j-1);
				aux = pos[j-1];
				pos[j-1] = pos[j];
				pos[j] = aux;
			}
		}
	}
	return mag;
}

void zera_coeficiente(complex double *coeficiente, int *pos, int C, int N){
	while(C <= N){
		coeficiente[pos[C]] = 0;
		C++;
	}
}
