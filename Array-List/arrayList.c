#include <ArrayList.h>

typedef struct NO{
	ITEM **list;//lista interna void
	int fimvet;//tamanho ocupado na lista
	int tamanho;//tamanho da lista interna
	struct NO *proximo;//proximo elemento da lista
}NO;

struct ArrayList{
	NO *inicio;
}

ArrayList *new_arrayList(){
	printf("To be implemented");
	return NULL;
}

int add_arrayList(ArrayList *arrayList, ITEM *element){
	printf("To be implemented");
	return 1;
}

int clear_arrayList(ArrayList *arrayList){
	printf("To be implemented");
	return 1;
}

ArrayList *clone_arrayList(ArrayList *arrayList){
	printf("To be implemented");
	return 1;
}

int contains_arrayList(ArrayList *arrayList, int chave){
	printf("To be implemented");
	return 1;
}

ITEM *get_arrayList(ArrayList *arrayList, int pos){
	printf("To be implemented");
	return 1;
}

int indexOf_arrayList(ArrayList *arrayList, int chave){
	printf("To be implemented");
	return 1;
}

int isEmpty_arrayList(ArrayList *arrayList){
	printf("To be implemented");
	return 1;
}

int remove_arrayList(ArrayList *arrayList, int pos){
	printf("To be implemented");
	return 1;
}

int set_arrayList(ArrayList *arrayList, int pos, ITEM *element){
	printf("To be implemented");
	return 1;
}

int size_arrayList(ArrayList *arrayList){
	printf("To be implemented");
	return 1;
}

ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex, int endIndex){
	printf("To be implemented");
	return 1;
}

int destruct_arrayList(ArrayList **arrayList){
	printf("To be implemented");
	return 1;
}

void print_arrayList(ArrayList *arrayList){
	ArrayList *paux;
	int i = 0;
	for(i = 0; i < paux != NULL; paux = paux-next){
		printf("%d: ", paux->globalBeginIndex + i);
		print_item(paux->item[i]);
	}
	printf("\n\n");
}















