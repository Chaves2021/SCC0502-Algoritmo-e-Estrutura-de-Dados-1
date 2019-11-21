#include<complex_sparse_matrix.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<defines.h>

MATRIX *complex_sparse_create(int rows_number, int cols_number, int constant){
	MATRIX *matrix;
	//Allocating matrix
	matrix = (MATRIX *) calloc(1, sizeof(MATRIX));
	//Defining matrix characteristics
	matrix->rows_number = rows_number;
	matrix->cols_number = cols_number;
	matrix->constant = constant;
	//Alocating indices
	matrix->row_index = (MATRIX_ELEM **) calloc(rows_number, sizeof(MATRIX_ELEM *));
	matrix->col_index = (MATRIX_ELEM **) calloc(cols_number, sizeof(MATRIX_ELEM *));
	return matrix;
}

int complex_sparse_insert(MATRIX *matrix, int row, int col, int value){
	if(!matrix) return INVALID_MATRIX;
	if(row >= matrix->rows_number || col >= matrix->cols_number || row < 0 || col < 0) return INVALID_POS;
	MATRIX_ELEM **row_pointer = &matrix->row_index[row];
	MATRIX_ELEM **col_pointer = &matrix->col_index[col];

	//While the row pointer is different of NULL, that means the element exists, and need to check it's position
	//And while the element col position is smaller than the col position wanted, go right to find this coordinate
	while(*row_pointer && ((*row_pointer)->col < col)) row_pointer = &(*row_pointer)->next_right;
	//While the col pointer is different of NULL, that means the element exists, and need to check it's position
	//And while the element row position is smaller than the row position wanted, go bottom to find this coordinate
	while(*col_pointer && ((*col_pointer)->row < row)) col_pointer = &(*col_pointer)->next_bottom;

	//if the element exists, so just change de elem value :)
	if(*row_pointer && *col_pointer && ((*row_pointer)->col == col) && ((*col_pointer)->row == row)) 
		(*row_pointer)->value = value;
	//But if the element does not exist, create it ;)
	else{
		MATRIX_ELEM *elem;
		elem = (MATRIX_ELEM *) malloc(sizeof(MATRIX_ELEM));
		elem->row = row;
		elem->col = col;
		elem->value = value;
		//Inserting this element into matrix
		elem->next_right = *row_pointer;
		elem->next_bottom = *col_pointer;
		*row_pointer = *col_pointer = elem;

	}
	return SUCCESS;
}

int complex_sparse_remove(MATRIX *matrix, int row, int col){
	if(!matrix) return INVALID_MATRIX;
	if(row >= matrix->rows_number || col >= matrix->cols_number || row < 0 || col < 0) return INVALID_POS;
	MATRIX_ELEM **row_pointer = &matrix->row_index[row];
	MATRIX_ELEM **col_pointer = &matrix->col_index[col];

	//While the row pointer is different of NULL, that means the element exists, and need to check it's position
	//And while the element col position is smaller than the col position wanted, go right to find this coordinate
	while(*row_pointer && ((*row_pointer)->col < col)) row_pointer = &(*row_pointer)->next_right;
	//While the col pointer is different of NULL, that means the element exists, and need to check it's position
	//And while the element row position is smaller than the row position wanted, go bottom to find this coordinate
	while(*col_pointer && ((*col_pointer)->row < row)) col_pointer = &(*col_pointer)->next_bottom;

	//if the element exists, remove it :)
	if(*row_pointer && *col_pointer && ((*row_pointer)->col == col) && ((*col_pointer)->row == row)){
		MATRIX_ELEM *aux = *row_pointer;
		*row_pointer = (*row_pointer)->next_right;
		*col_pointer = (*col_pointer)->next_bottom;
		free(aux);
	}	
	//if not, bad news... :(
	else return NOT_FOUND;
	return SUCCESS;
}

int __complex_sparse_get(MATRIX *matrix, int row, int col){
	if(!matrix) return INVALID_MATRIX;
	if(row >= matrix->rows_number || col >= matrix->cols_number || row < 0 || col < 0) return INVALID_POS;
	MATRIX_ELEM **row_pointer = &matrix->row_index[row];

	//While the row pointer is different of NULL, that means the element exists, and need to check it's position
	//And while the element col position is smaller than the col position wanted, go right to find this coordinate
	while(*row_pointer && ((*row_pointer)->col < col)) row_pointer = &(*row_pointer)->next_right;

	//if the element exists, return it :)
	if(*row_pointer && ((*row_pointer)->col == col)){
		return (*row_pointer)->value;
	}
	//if not, bad news... :(
	else return matrix->constant;
}

MATRIX *complex_sparse_add(MATRIX *first, MATRIX *second){
	int indice;
	int value;
	MATRIX *matrix_add;
	MATRIX_ELEM *p;
	MATRIX_ELEM *q;
	matrix_add = complex_sparse_create(first->rows_number, first->cols_number, 0);
	/*
	for(indice = 0; indice < matrix_add->rows_number; indice++){
		for(p = first->row_index[indice]; p; p = p->next_right){
			value = __complex_sparse_get(first, p->row, p->col) + __complex_sparse_get(second, p->row, p->col);
			complex_sparse_insert(matrix_add, p->row, p->col, value);
		}
	}
	*/
	for(indice = 0; indice < matrix_add->rows_number; indice++){
		p = first->row_index[indice]; q = second->row_index[indice];
		while(p || q){
			if(p && q){
				value = __complex_sparse_get(first, p->row, p->col) + __complex_sparse_get(second, p->row, p->col);
				complex_sparse_insert(matrix_add, p->row, p->col, value);
				p = p->next_right;
				q = q->next_right;
			}
			else if(p){
				value = __complex_sparse_get(first, p->row, p->col) + __complex_sparse_get(second, p->row, p->col);
				complex_sparse_insert(matrix_add, p->row, p->col, value);
				p = p->next_right;
			}
			else{
				value = __complex_sparse_get(first, q->row, q->col) + __complex_sparse_get(second, q->row, q->col);
				complex_sparse_insert(matrix_add, q->row, q->col, value);
				q = q->next_right;
			}
		}
	}
	return matrix_add;
}

MATRIX *complex_sparse_mult(MATRIX *first, MATRIX *second){
	int i;
	MATRIX *mult_matrix;
	mult_matrix = complex_sparse_create(first->rows_number, first->cols_number, 0);
	for(i = 0; i < mult_matrix->rows_number; i++){
	}
	return mult_matrix;
}

int complex_sparse_print(MATRIX *matrix){
	if(!matrix) return INVALID_MATRIX;
	int indice;
	MATRIX_ELEM *p;

	printf("-1 %d %d\n", matrix->rows_number, matrix->cols_number);
	for(indice = 0; indice < matrix->rows_number; indice++){
		for(p = matrix->row_index[indice]; p; p = p->next_right){
			printf("%d %d %d\n", p->row, p->col, p->value);
		}
	}
	return SUCCESS;
}
