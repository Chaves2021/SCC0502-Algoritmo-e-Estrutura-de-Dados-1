#include <array_List.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	char *comando;
	comando = (char *) calloc(30, sizeof(char));
	scanf(" %s", comando);
	int pos;
	int beginIndex, endIndex;
	int chave;
	int item;
	ArrayList *my = new_arrayList();
	do{
		if(strcmp("tamanho", comando) == 0)
			printf("%d\n",size_arrayList(my));
		else if(strcmp("add",comando) == 0){
			scanf("%d", &chave);
			scanf("%d", &item);
			add_arrayList(my, chave, item);
		}
		else if(strcmp("sub", comando) == 0){
			scanf("%d %d", &beginIndex, &endIndex);
			subArray_arrayList(my, beginIndex, endIndex);
		}	
		else if(strcmp("set", comando) == 0){
			scanf("%d %d", &pos, &chave);
			scanf("%d", &item);
			set_arrayList(my, pos, chave, item);
		}	
		else if(strcmp("print", comando) == 0){
			print_arrayList(my);
		}
		else if(strcmp("contem", comando) == 0){
			scanf("%d", &chave);
			printf("%d\n", contains_arrayList(my, chave));
		}
		else if(strcmp("indice", comando) == 0){
			scanf("%d", &chave);
			printf("%d\n", indexOf_arrayList(my, chave));
		}
		else if(strcmp("vazia", comando) == 0){
			printf("%d\n", isEmpty_arrayList(my));
		}
		else if(strcmp("remover", comando) == 0){
			scanf("%d", &pos);
			remove_arrayList(my, pos);
		}
		else if(strcmp("get", comando) == 0){
			scanf("%d", &pos);
			printf("%d/%d\n", get_Item(my, pos)->chave, get_Item(my, pos)->item);

		}
		scanf(" %s", comando);
	}while(strcmp("sair", comando) != 0);


	return 0;
}
