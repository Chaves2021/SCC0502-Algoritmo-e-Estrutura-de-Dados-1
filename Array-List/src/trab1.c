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

	if(get_Item(my, 3) != NULL){
		int *item = get_Item(my,3)->item;
		printf("Chave: %d\nValor: %d\n\n",get_Item(my,3)->chave,*item); 
	}

	return 0;
}
