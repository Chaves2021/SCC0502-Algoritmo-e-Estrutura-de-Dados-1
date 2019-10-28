#include <stdio.h>
#include <stdlib.h>
#include <complex_sparse_cube.h>
#include <string.h>
#include <defines.h>

int main(void){
	long int x, y, z;
	float aux;
	long int d1, d2, d3;
	long double elem;
	int error;
	char *comando;
	comando = (char *) calloc(10, sizeof(char));
	COMPLEX_SPARSE_CUBE *cube;
	scanf("%f", &aux);
	x = (long int) aux;
	scanf("%f", &aux);
	y = (long int) aux;
	scanf("%f", &aux);
	z = (long int) aux;

	//Criando o cubo
	cube = complex_sparse_cube_create(x, y, z,0);
	while(scanf(" %s", comando) != EOF){
		if(strcmp(comando, "put") == 0){
			scanf("%f", &aux);
			d1 = (long int) aux;
			scanf("%f", &aux);
			d2 = (long int) aux;
			scanf("%f", &aux);
			d3 = (long int) aux;
			//Lendo elemento
			scanf("%Lf", &elem);
			complex_sparse_cube_put(cube, d1, d2, d3, elem, &error);
		}
		else if(strcmp(comando, "get") == 0){
			scanf("%f", &aux);
			d1 = (long int) aux;
			scanf("%f", &aux);
			d2 = (long int) aux;
			scanf("%f", &aux);
			d3 = (long int) aux;
			scanf("%Lf", &elem);
			printf("%Lf\n", complex_sparse_cube_get(cube, d1, d2, d3, &error));
		}
		else if(strcmp(comando, "remove") == 0){
			scanf("%f", &aux);
			d1 = (long int) aux;
			scanf("%f", &aux);
			d2 = (long int) aux;
			scanf("%f", &aux);
			d3 = (long int) aux;
			scanf("%Lf", &elem);
			complex_sparse_cube_remove(cube, d1, d2, d3, &error);
		}


	}


	return SUCCESS;
}
