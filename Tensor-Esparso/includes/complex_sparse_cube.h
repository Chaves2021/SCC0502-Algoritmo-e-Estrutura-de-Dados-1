#ifndef _COMPLEX_SPARSE_CUBE_H_
#define _COMPLEX_SPARSE_CUBE_H_

struct complex_sparse_cube_elem {
	long int d1, d2, d3;
	long double elem;
	struct complex_sparse_cube_elem *d1_next, *d2_next, *d3_next;
};

struct complex_sparse_plane_elem {
	long int x, y;
	struct complex_sparse_plane_elem *x_next, *y_next;
	struct complex_sparse_cube_elem *three_d_element;
};

struct complex_sparse_plane {
	long int x_dim, y_dim;
	struct complex_sparse_plane_elem **x_index, **y_index;
};

struct complex_sparse_cube {
	double constant;
	struct complex_sparse_plane *d1_d2, *d2_d3, *d3_d1;
};

typedef struct complex_sparse_cube COMPLEX_SPARSE_CUBE;
typedef struct complex_sparse_plane COMPLEX_SPARSE_PLANE;
typedef struct complex_sparse_plane_elem COMPLEX_SPARSE_PLANE_ELEM;
typedef struct complex_sparse_cube_elem COMPLEX_SPARSE_CUBE_ELEM;

COMPLEX_SPARSE_CUBE *complex_sparse_cube_create( long int d1_dim, long int d2_dim, long int d3_dim, double constant);

int complex_sparse_cube_put(COMPLEX_SPARSE_CUBE *cube, long int d1, long int d2, long int d3, long double elem, int *error);

long double complex_sparse_cube_get(COMPLEX_SPARSE_CUBE *cube, long int d1, long int d2, long int d3, int *error);

int complex_sparse_cube_remove(COMPLEX_SPARSE_CUBE *cube, long int d1, long int d2, long int d3, int *error);

int complex_sparse_cube_free(COMPLEX_SPARSE_CUBE *cube);
#endif
