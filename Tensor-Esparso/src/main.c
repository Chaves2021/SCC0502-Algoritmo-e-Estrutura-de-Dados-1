#include <stdio.h>
#include <stdlib.h>
#include <complex_sparse_cube.h>

int main(void){
	int x, y, z;
	int d1, d2, d3;
	double elem;
	int error;
	COMPLEX_SPARSE_CUBE *cube;

	scanf("%d %d %d", &x, &y, &z);
	//Criando o cubo
	cube = complex_sparse_cube_create(x, y, z,0);
	//Lendo elemento
	scanf("%lf", &elem);
	//Lendo coordenadas do elemento
	scanf("%d %d %d", &d1, &d2, &d3);
	complex_sparse_cube_put(cube, d1, d2, d3, elem, &error);

	return 0;
}
