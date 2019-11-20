struct MATRIX_ELEM{
	int row;
	int col;
	double value;
	//element at the right side of this element
	struct MATRIX_ELEM *next_right;
	//element at the bottom side of this element
	struct MATRIX_ELEM *next_bottom;
};
typedef struct MATRIX_ELEM MATRIX_ELEM;

struct MATRIX{
	int rows_number;
	int cols_number;
	double constant;
	//row index will store the adress of the pointer that points to the first element of each matrix row
	MATRIX_ELEM **row_index;
	//col index will store the adress of the pointer that points to the first element of each matrix col
	MATRIX_ELEM **col_index;
};
typedef struct MATRIX MATRIX;

//Function to create matrix
MATRIX *complex_sparse_create(int, int, double);
//Function to insert an element
int complex_sparse_insert(MATRIX *, int, int, double);
//Function to remove an element
int complex_sparse_remove(MATRIX *, int, int);
//Function to sum 2 matrix
MATRIX *complex_sparse_add(MATRIX *, MATRIX *);
//Function to multiply 2 matrix
MATRIX *complex_sparse_mult(MATRIX *, MATRIX *);
