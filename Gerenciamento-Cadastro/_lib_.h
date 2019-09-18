#ifndef _lib_
#define _lib_

//Corpo de 1 elemento generico da lista
struct REGISTER_ELEM{
	char *first_name;
	char *last_name;
	char *cpf;
	char *tel;
	struct REGISTER_ELEM *next;
	struct REGISTER_ELEM *prev;
};

//Descritor da lista
struct REGISTER{
	struct REGISTER_ELEM *first; 
	struct REGISTER_ELEM *last; 
	int count;
};

#define SUCCESS         0 
#define INVALID_LIST   -1
#define REMOVE_ERROR   -2
#define GET_ERROR      -3
#define INVALID_POS    -4
#define ELEM_NOT_FOUND -5

//Funcao para alocar a lista
REGISTER *create_register(void);
//Funcao para alocar um elemento na lista
int add(REGISTER *, int, char *);
//Funcao para recuperar um elemento da lista pela posicao
REGISTER_ELEM *get_register(REGISTER *, int);
void dump(REGISTER *);
void remove(REGISTER *, char *);
void exit();

#endif
