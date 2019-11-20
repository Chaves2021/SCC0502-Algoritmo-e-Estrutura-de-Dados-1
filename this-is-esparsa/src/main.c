#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex_sparse_matrix.h>
#include<defines.h>
int main(void){
	int rows_number = 10;
	int cols_number = 10;
	int row = 0;
	int col = 3;
	int value = 100;
	MATRIX *matrix = complex_sparse_create(rows_number, cols_number, 0);
	complex_sparse_insert(matrix, row, col, value);
	complex_sparse_insert(matrix, row + 1, col + 1, value / 10);
	complex_sparse_insert(matrix, row + 2, col - 1, value + 100);
	complex_sparse_remove(matrix, row, col);




	return SUCCESS;
}
