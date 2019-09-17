#include <stdio.h>
#include <stdlib.h>
#include <_lib_.h>

REGISTER *create_register(void){
	REGISTER *my_reg;
	my_reg = (REGISTER *) calloc(1, sizeof(REGISTER));
	if(!my_reg) return INVALID_LIST;

	return my_reg
}
