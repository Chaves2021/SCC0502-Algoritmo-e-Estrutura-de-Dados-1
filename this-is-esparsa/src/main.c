#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex_sparse_matrix.h>
#include<defines.h>
int main(void){
	MATRIX *first;
	MATRIX *second;
	MATRIX *third;
	char operation;
	int rows_number, cols_number, constant;
	int row = 0, col = 0, value = 0;

	//Storing operation
	scanf("%c", &operation);

	//reading first matrix
	scanf("%d %d %d", &constant, &rows_number, &cols_number);
	first = complex_sparse_create(rows_number, cols_number, 0);
	while(scanf("%d %d %d", &row, &col, &value) && row != -1){
		complex_sparse_insert(first, row, col, value);
	}

	//reading second matrix
	second = complex_sparse_create(col, value, 0);
	while(scanf("%d %d %d", &row, &col, &value) != EOF){
		complex_sparse_insert(second, row, col, value);
	}

	if(operation == 'M') third = complex_sparse_mult(first, second);
	else if(operation == 'A') third = complex_sparse_add(first, second);

	//Print the answer
	complex_sparse_print(third);

	/*
	complex_sparse_free(first);
	complex_sparse_free(second);
	complex_sparse_free(third);
	*/

	return SUCCESS;
}
