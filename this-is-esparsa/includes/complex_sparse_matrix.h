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

MATRIX *complex_sparse_create(int, int, double);
int complex_sparse_insert(int, int, double);
int complex_sparse_remove(int, int);
MATRIX *complex_sparse_add(MATRIX *, MATRIX *);
MATRIX *complex_sparse_mult(MATRIX *, MATRIX *);
