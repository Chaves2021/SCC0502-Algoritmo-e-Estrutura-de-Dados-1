#ifndef _COMPLEX_SPARSE_MATRIX_
#define _COMPLEX_SPARSE_MATRIX_
struct MATRIX_ELEM{
	int row;
	int col;
	int value;
	//element at the right side of this element
	struct MATRIX_ELEM *next_right;
	//element at the bottom side of this element
	struct MATRIX_ELEM *next_bottom;
};
typedef struct MATRIX_ELEM MATRIX_ELEM;

struct MATRIX{
	int rows_number;
	int cols_number;
	int constant;
	//row index will store the adress of the pointer that points to the first element of each matrix row
	MATRIX_ELEM **row_index;
	//col index will store the adress of the pointer that points to the first element of each matrix col
	MATRIX_ELEM **col_index;
};
typedef struct MATRIX MATRIX;

//Function to create matrix
MATRIX *complex_sparse_create(int, int, int);
//Function to insert an element
int complex_sparse_insert(MATRIX *, int, int, int);
//Function to remove an element
int complex_sparse_remove(MATRIX *, int, int);
//Function to sum 2 matrix
MATRIX *complex_sparse_add(MATRIX *, MATRIX *);
//Function to multiply 2 matrix
MATRIX *complex_sparse_mult(MATRIX *, MATRIX *);
//Function to print matrix
int complex_sparse_print(MATRIX *);
//Function to free matrix
int complex_sparse_free(MATRIX *);


#endif
