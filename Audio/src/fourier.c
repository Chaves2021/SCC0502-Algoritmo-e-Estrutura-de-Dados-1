#include <stdio.h>
#include <stdlib.h>
#include <file.h>
#include <math.h>
#include <complex.h>

void troca(double *vetor, int pos0, int pos1){
	double aux;
	aux = vetor[pos0];
	vetor[pos0] = vetor[pos1];
	vetor[pos1] = aux;
}

complex double *dft(unsigned char *valor, int N){
	int k, t;
	double x;
	complex double *coeficiente;
	coeficiente = (complex double *) malloc((N / 2 + 1) * sizeof(complex double *));
	complex double z;
	for(k = 0; k <= N/2; k++){
		z = 0;
		for(t = 0; t < N; t++){
			x = 2 * k * acos(-1) * (t / N);
			z += cexp(-1 * x * I) * valor[t];
		}
		if(k == 0)
			coeficiente[k] = (1.0 / N) * z;
		else
			coeficiente[k] = (2.0 / N) * z;
	}
	return coeficiente;
}
