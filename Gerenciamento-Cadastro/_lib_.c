#include <stdio.h>
#include <stdlib.h>
#include <_lib_.h>

REGISTER *create_register(void){
	REGISTER *my_reg;
	my_reg = (REGISTER *) calloc(1, sizeof(REGISTER));
	if(!my_reg) return INVALID_LIST;

	return my_reg
}

//A funcao aloca sempre um char a mais por conta do \0
int add(REGISTER *, int, char *){
	REGISTER_ELEM *new;
	new = (REGISTER_ELEM *) malloc(sizeof(REGISTER_ELEM));
	new->first_name = (char *) malloc(16 * sizeof(char));
	new->last_name = (char *) malloc(16 * sizeof(char));
	new->cpf = (char *) malloc(12 * sizeof(char));
	new->tel = (char *) malloc(21 * sizeof(char));

	scanf(" %s", first_name);
	scanf(" %s", last_name);
	scanf(" %s", cpf);
	scanf(" %s", tel);

	return SUCCESS;
}
