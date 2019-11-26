#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sudoku.h>
#include<defines.h>

char **allocMat(int col, int row){
	int i;
	char **matrix;
	//Allocating matrix
	matrix = (char **) calloc(col, sizeof(char *));
	for(i = 0; i < col; i++) matrix[i] = (char *) calloc(row, sizeof(char));
	return matrix;
}

char **readMat(char **matrix, char *path, int col, int row){
	int i, j;
	FILE *file;
	char file_content;
	file = fopen(path, "r");
	file_content = fgetc(file);
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			if(file_content != '\n'){
				matrix[i][j] = file_content;
			}
			else j -= 1;
			file_content = fgetc(file);
		}
	}
	fclose(file);
	return matrix;
}

int printMat(char **matrix, int col, int row){
	int i, j;
	for(i = 0; i < row; i++){
		for(j = 0; j < row; j++){
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}
