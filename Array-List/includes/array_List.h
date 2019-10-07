#ifndef array_List
#define array_List

typedef struct ITEM{
	void *item;
	int chave;
}ITEM;

typedef struct NO{
	ITEM **elemento;//lista interna void
	int fimVet;//tamanho ocupado na lista
	int tamanho;//tamanho da lista interna
	int tamMax;//tamanho maximo da lista interna
	struct NO *proximo;//proximo elemento da lista
}NO;

typedef struct ArrayList{
	NO *inicio;
}ArrayList;

//Cria a ArrayList e aloca toda a memoria necessaria
ArrayList *new_arrayList();

//Adiciona elemento ao arraylist
int add_arrayList(ArrayList *arrayList, ITEM *elemento);

//Verifica no ArrayList se existe um elemento com a chave informada
int contains_arrayList(ArrayList *arrayList, int chave);

//Recupera um item na posicao informada
ITEM *get_Item(ArrayList *arrayList, int pos);

//Retorna qual a posicao do primeiro elemento com a chave informada
int indexOf_arrayList(ArrayList *arrayList, int chave);

//Verifica se o ArrayList esta vazio
int isEmpty(ArrayList *arrayList);

//Remove um elemento da lista
int remove_arrayList(ArrayList *arrayList, int pos);

//Modifica um elemento do ArrayList
int set_arrayList(ArrayList *arrayList, int pos, ITEM *element);

//Retorna o tamanho total do ArrayList
int size_arrayList(ArrayList *arrayList);

//Recupera um novo subarray no intervalo [beginIndex, endIndex[
ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex, int endIndex);

//Desaloca memoria alocada pelo ArrayList
int destruct_arrayList(ArrayList **arrayList);

//Imprime toda a lista
void print_arrayList(ArrayList *arrayList);

#endif