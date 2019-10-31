#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	//n se refere ao tamanho do vetor de entrada
	//i se refere a percursao da somatoria
	//k se refere ao numero que varia de 0 a n-1 a cada passo da somatoria
	//x armazena o vetor de entrada
	int n, i, k;
	double *x = NULL;
	double *resultado = NULL;
	resultado = (double *) calloc(1, sizeof(double));
	scanf("%d", &n);
	x = (double *) malloc(n * sizeof(double));
	//caso k seja igual a 0, e necessario armazenar os valores do vetor de entrada
	for(int k = 0; k < n; k++){
		for(i = 0; i < n; i++){
			if(k == 0)
				scanf("%lf", &x[i]);
			*resultado += x[i] * cos((M_PI / n) * (i + 0.5) * k);
		}
		printf("%lf\n", *resultado);
		*resultado = 0;
	}

	free(resultado);
	free(x);
	return 0;
}
