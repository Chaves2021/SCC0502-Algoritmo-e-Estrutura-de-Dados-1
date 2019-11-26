#include<stdio.h>
#include<stdlib.h>
#include<sudoku.h>
#include<defines.h>

int main(void){
	char **matrix;
	char *path;
	path = (char *) malloc(30 * sizeof(char));
	scanf(" %s", path);
	matrix = allocMat(MATRIX_SIZE, MATRIX_SIZE);
	matrix = readMat(matrix, path, MATRIX_SIZE, MATRIX_SIZE);
	printMat(matrix, MATRIX_SIZE, MATRIX_SIZE);
	return SUCCESS;
}
