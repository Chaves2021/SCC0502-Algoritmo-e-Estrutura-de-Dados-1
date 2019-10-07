#include <array_List.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


int main(void){
	int a =1;
	int c =3;
	int d =4;
	int e =5;

	ArrayList *my = new_arrayList();
	ITEM *elemento = (ITEM *) calloc(1,sizeof(ITEM));

	elemento->item = (void *) &a;
	elemento->chave = 2;
	add_arrayList(my, elemento);
	
	elemento = (ITEM *) calloc(1,sizeof(ITEM));
	elemento->item = (void *) &c;
	elemento->chave = 10;
	add_arrayList(my, elemento);

	elemento = (ITEM *) calloc(1,sizeof(ITEM));
	elemento->item = (void *) &d;
	elemento->chave = 7;
	add_arrayList(my, elemento);
	
	elemento = (ITEM *) calloc(1,sizeof(ITEM));
	elemento->item = (void *) &e;
	elemento->chave = 2;
	add_arrayList(my, elemento);

	print_arrayList(my);

	if(contains_arrayList(my, 7))
		printf("\n**ACHOU**\n");
	else
		printf("\n**NÃO ACHOU**\n");



	return 0;
}
