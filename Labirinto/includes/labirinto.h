#ifndef _LABIRINTO_H_
#define _LABIRINTO_H_
struct camara{
	int indice;
	int portal; //caso 0, nao ha como acessar
	int saida; //booleano
};
typedef struct camara CAMARA;

struct segmento{
	int indice_1;
	int indice_2;
	CAMARA *extremidade_1;
	CAMARA *extremidade_2;
	struct segmento *seg_1;
	struct segmento *seg_2;
	int comprimento;
};
typedef struct segmento SEGMENTO;
#endif
