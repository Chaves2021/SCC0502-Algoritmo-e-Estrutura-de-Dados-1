#include <array_List.h>
#include <defines.h>
#include <stdio.h>
#include <stdlib.h>

ArrayList *new_arrayList(){
	ArrayList *new;
	new = (ArrayList *) malloc(1 * sizeof(ArrayList));
	NO *new_no = (NO *) calloc(1,sizeof(NO));
	new_no->tamMax = 10;
	new_no->elemento = (ITEM **) calloc(new_no->tamMax, sizeof(ITEM *));
	new->inicio = new_no;
	return new;
}

int insercao(NO *vetor, ITEM *elemento, int indiceDireito){
	int i;
	for(i = indiceDireito; i >= 0 && elemento->chave < vetor->elemento[i]->chave; i--){
		vetor->elemento[i+1] = vetor->elemento[i];
	}
	vetor->elemento[i+1] = elemento;
	return SUCCESS;

}

int add_arrayList(ArrayList *arrayList, int chave, void *elem){
	if(!arrayList) return INVALID_LIST;
	int flag = 0;
	ITEM *elemento = (ITEM *) calloc(1, sizeof(ITEM));
	elemento->chave = chave;
	elemento->item = elem;
	int i;
	int indice = 0;
	int tam = arrayList->inicio->tamanho;
	NO *aux = arrayList->inicio;
	for(i = 0; !flag; i++){
		if(i == tam){
			if(aux->proximo != NULL){
				aux = aux->proximo;
				tam = aux->tamanho;
				i = 0;
			}
			else if(i == aux->tamMax){
				NO *new = (NO *) calloc(1,sizeof(NO));
				new->tamMax = tam * 2;
				new->elemento = (ITEM **) calloc(new->tamMax, sizeof(ITEM));
				new->elemento[0] = elemento;
				aux->proximo = new;
				return SUCCESS;
			}
			else{
				insercao(aux, elemento, tam - 1);
				aux->tamanho++;
				return SUCCESS;
			}
		}
	}
	return SUCCESS;
}

/*
int clear_arrayList(ArrayList *arrayList){
	printf("To be implemented");
	return 1;
}
*/

/*
ArrayList *clone_arrayList(ArrayList *arrayList){
	printf("To be implemented");
	return (ArrayList *)1;
}
*/

int contains_arrayList(ArrayList *arrayList, int chave){
	if(!arrayList) return INVALID_LIST;
	NO *no = arrayList->inicio;
	int tamanho = no->tamanho - 1;
	int meio = tamanho / 2;
	while(1){
		if(meio == tamanho || meio == 0){
			if(no->elemento[meio]->chave == chave) return 1;
			else if(no->proximo != NULL){
			       	no = no->proximo;
				tamanho = no->tamanho - 1;
				meio = tamanho / 2;
			}
			else return 0;
		}
		else{
			if(no->elemento[meio]->chave == chave) return 1;
			else if(chave > no->elemento[meio]->chave) meio = ((meio + 1) + tamanho) / 2;
			else if(chave < no->elemento[meio]->chave) meio = (meio - 1) / 2;
		}
	}
	return 0;
}

ITEM *get_Item(ArrayList *arrayList, int pos){
	NO *no = arrayList->inicio;
	int i, cont = 0;
	int flag = 0;
	while(1){	
		if(pos >= no->tamanho && no->proximo != NULL){
			//o tamanho do no comeca em 1, mas a pos comeca em 0, por isso a decrementacao
			cont = no->tamanho - 1;
			no = no->proximo;
		}
		else if(pos < no->tamanho){
			return no->elemento[pos - cont];
		}
		else{
			return NULL;
		}
	}
}

int indexOf_arrayList(ArrayList *arrayList, int chave){
	if(!arrayList) return INVALID_LIST;
	NO *no = arrayList->inicio;
	int i;
	int indice = 0;
	for(i = 0, indice; i < no->tamanho; i++, indice++){
		if(i >= no->tamanho && no->proximo){
			i = 0;
			no = no->proximo;
		}
		else
			if(no->elemento[i]->chave == chave)
				return indice;
			
	}
	return INVALID_KEY;
	
}

int isEmpty_arrayList(ArrayList *arrayList){
	if(!arrayList) return INVALID_LIST;
	if(arrayList->inicio->tamanho) return 0;
	return 1;
}

//TODO
//O ERRO ESTA NO FREE QUE ESTA COMENTADO
//EU SEI QUE VOCE CONSEGUE IRMAO
int remove_arrayList(ArrayList *arrayList, int pos){
	if(!arrayList) return INVALID_LIST;
	NO *no = arrayList->inicio;
	NO *follow;
	int i, cont = 0;
	int flag = 0;
	while(1){	
		if(pos >= no->tamanho && no->proximo != NULL){
			cont = no->tamanho - 1;
			follow = no;
			no = no->proximo;
		}
		else if(pos < no->tamanho){
			free(no->elemento[pos - cont]);
			no->tamanho--;
			if(!follow && !no->tamanho){ 
				arrayList->inicio = no->proximo; 
				free(no);
			}
			else if(!no->tamanho){
				follow->proximo = no->proximo;
				free(no);
			}
			else{
				for(i = pos; i < no->tamanho; i++)
					no->elemento[i] = no->elemento[i + 1];
				//free(no->elemento[i]);

			}
			return SUCCESS;
		}
		else{
			return INVALID_KEY;
		}
	}
	return 1;
}

int set_arrayList(ArrayList *arrayList, int pos, ITEM *element){
	printf("To be implemented");
	return 1;
}

int size_arrayList(ArrayList *arrayList){
	return 1;
}

/*
ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex,int endIndex){
	printf("To be implemented...");
	return 1;
}
*/

int destruct_arrayList(ArrayList **arrayList){
	printf("To be implemented");
	return 1;
}

void print_arrayList(ArrayList *arrayList){
	NO *no = arrayList->inicio;
	int tamanho = no->tamanho;
	int i;
	int flag = 0;
	int *item;
	for(i = 0; !flag; i++){	
		if(i == tamanho && no->proximo != NULL){
			no = no->proximo;
			i = 0;
		}
		else if(i == tamanho && no->proximo == NULL){
			flag = 1;
		}
		if(i != tamanho){
			item = (int *) no->elemento[i]->item;
			printf("Elem[%d]\nChave: %d\nValor: %d\n\n", i, no->elemento[i]->chave, *item);
		}
	}
}
