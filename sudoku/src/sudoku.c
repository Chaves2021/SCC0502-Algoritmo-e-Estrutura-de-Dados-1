#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sudoku.h>

char **allocMat(int col, int row){
	int i;
	char **matrix;
	//Allocating matrix
	matrix = (char **) calloc(col, sizeof(char *));
	for(i = 0; i < col; i++) matrix[i] = (char *) calloc(row, sizeof(char));
	return matrix;
}

//TODO
//Need to end readMat
char **readMat(char *path, int *col, int *row){
	FILE *file;
	char file_content;
	file = fopen(path, "r");
}
