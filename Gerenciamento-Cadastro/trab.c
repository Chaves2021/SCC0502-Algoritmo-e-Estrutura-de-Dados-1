//Caio Marcos Chaves Viana      nusp: 11208217

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<_lib_.h>

int main(void){
	char *escolha;
	char *cpf;
	REGISTER *my_reg;
	my_reg = create_register();
	escolha = (char *) calloc(20, sizeof(char));
	cpf = (char *) calloc(12, sizeof(char));
	scanf(" %s", escolha);
	while(strcmp(escolha,"sair") != 0){
		if(strcmp(escolha,"buscar") == 0){
			scanf(" %s", cpf);
			search(my_reg, cpf);
		}
		if(strcmp(escolha,"remover") == 0){
			scanf(" %s", cpf);
			remover(my_reg, cpf);
		}
		if(strcmp(escolha,"cadastrar") == 0){
			add(my_reg);
		}
		if(strcmp(escolha,"dump") == 0){
			dump(my_reg);
		}
		scanf(" %s", escolha);
	}
	return 0;
}
