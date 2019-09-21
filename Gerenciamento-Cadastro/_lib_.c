//Caio Marcos Chaves Viana      nusp: 11208217

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <_lib_.h>

REGISTER *create_register(void){
	REGISTER *my_reg;
	my_reg = (REGISTER *) calloc(1, sizeof(REGISTER));
	if(!my_reg) return NULL;

	return my_reg;
}

//A funcao aloca sempre um char a mais por conta do \0
int add(REGISTER *my_reg){
	if(!my_reg) return INVALID_LIST;
	int counter = 0;
	REGISTER_ELEM **p;
	p = &(my_reg->first);

	REGISTER_ELEM *new;
	new = (REGISTER_ELEM *) calloc(1,sizeof(REGISTER_ELEM));
	new->first_name = (char *) calloc(16, sizeof(char));
	new->last_name = (char *) calloc(16, sizeof(char));
	new->cpf = (char *) calloc(12, sizeof(char));
	new->tel = (char *) calloc(21, sizeof(char));

	scanf(" %s", new->first_name);
	scanf(" %s", new->last_name);
	scanf(" %s", new->cpf);
	scanf(" %s", new->tel);

	while(counter++ < my_reg->count && (p = &(*p)->next));
	*p = new;
	new->prev = my_reg->last;
	my_reg->last = new;
	my_reg->count++;

	return SUCCESS;
}


int search(REGISTER *my_reg, char *cpf){
	if(!my_reg) return INVALID_LIST;
	int counter = 0;
	REGISTER_ELEM *p = my_reg->first;
	while(counter++ < my_reg->count){
		if(strcmp(p->cpf,cpf) == 0){
			printf("Primeiro Nome: %s\n", p->first_name);
			printf("Ultimo Nome: %s\n", p->last_name);
			printf("CPF: %s\n", p->cpf);
			printf("Telefone: %s\n", p->tel);
			printf("-----------------------------\n");
			return SUCCESS;
		}
		else
			p = p->next;
	}
	return INVALID_CPF;
}

int dump(REGISTER *my_reg){
	if(!my_reg) return INVALID_LIST;
	int counter = 0;
	REGISTER_ELEM *p = my_reg->first;
	while(counter++ < my_reg->count){
		printf("Primeiro Nome: %s\n", p->first_name);
		printf("Ultimo Nome: %s\n", p->last_name);
		printf("CPF: %s\n", p->cpf);
		printf("Telefone: %s\n", p->tel);
		printf("-----------------------------\n");
		p = p->next;
	}
	return SUCCESS;
}

int remover(REGISTER *my_reg, char *cpf){
	if(!my_reg) return INVALID_LIST;
	int counter = 0;
	REGISTER_ELEM *p;
	p = my_reg->first;
	while(counter++ < my_reg->count){
		if(strcmp(p->cpf,cpf) == 0){
			if(p->prev)
				p->prev->next = p->next;
			else
				my_reg->first = p->next;
			if(p->next)
				p->next->prev = p->prev;
			else
				my_reg->last = p->prev;
			free(p);
			my_reg->count--;
			return SUCCESS;
		}
		else
			p = p->next;
	}
	return INVALID_CPF;
}
