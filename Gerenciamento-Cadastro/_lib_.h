//Caio Marcos Chaves Viana      nusp: 11208217
//
//Foi escolhido o algoritmo da lista duplamente encadeada pelo fato de eu ter entendi melhor o algoritmo
//Principalmente a funcao de remover, que estava mais fresca na memoria do que a da lista simplesmente encadeada
//Mesmo imaginando que a lista simplesmente encadeada tenha uma complexidade menor, e o ponteiro prev so tem uso real na funcao de remover

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

typedef struct REGISTER REGISTER;
typedef struct REGISTER_ELEM REGISTER_ELEM;
#define SUCCESS         0 
#define INVALID_LIST   -1
#define REMOVE_ERROR   -2
#define GET_ERROR      -3
#define ELEM_NOT_FOUND -4
#define INVALID_CPF    -5

//Funcao para alocar a lista
REGISTER *create_register(void);
//Funcao para alocar um elemento na lista
int add(REGISTER *);
//funcao para imprimir elemento da lista
int search(REGISTER *, char *);
//Funcao para exibir todos os elementos da lista
int dump(REGISTER *);
//Funca para remover elemento da lista
int remover(REGISTER *, char *);
void exit();

#endif
