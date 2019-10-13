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

int add_arrayList(ArrayList *arrayList, int chave, int elem){
	if(!arrayList) return INVALID_LIST;
	int flag = 0;
	ITEM *elemento = (ITEM *) calloc(1, sizeof(ITEM));
	elemento->chave = chave;
	elemento->item = elem;
	int i;
	NO *aux = arrayList->inicio;
	for(i = 0; !flag; i++){
		if(i == aux->tamanho){
			if(aux->proximo != NULL){
				aux = aux->proximo;
				i = -1;
			}
			else if(i == aux->tamMax){
				NO *new = (NO *) calloc(1,sizeof(NO));
				new->tamMax = aux->tamanho * 2;
				new->elemento = (ITEM **) calloc(new->tamMax, sizeof(ITEM));
				new->elemento[0] = elemento;
				new->tamanho++;
				aux->proximo = new;
				return SUCCESS;
			}
			else{
				insercao(aux, elemento, aux->tamanho - 1);
				aux->tamanho++;
				return SUCCESS;
			}
		}
	}
	return SUCCESS;
}

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
	if(!arrayList) return (ITEM *) INVALID_LIST;
	NO *no = arrayList->inicio;
	int total = 0;
	while(1){	
		if(pos >= no->tamanho + total && no->proximo != NULL){
			total += no->tamanho;
			no = no->proximo;
		}
		else if(pos < no->tamanho + total){
			return no->elemento[pos - total];
		}
		else{
			return (ITEM *) INVALID_POS;
		}
	}
}

int indexOf_arrayList(ArrayList *arrayList, int chave){
	if(!arrayList) return INVALID_LIST;
	NO *no = arrayList->inicio;
	int i;
	int indice = 0;
	int flag = 0;
	for(i = 0; !flag; i++, indice++){
		if(i >= no->tamanho && no->proximo){
			i = 0;
			no = no->proximo;
		}
		else if(i < no->tamanho){
			if(no->elemento[i]->chave == chave)
				return indice;
		}
		else
			return INVALID_KEY;
	}
	return INVALID_KEY;
	
}

int isEmpty_arrayList(ArrayList *arrayList){
	if(!arrayList) return INVALID_LIST;
	if(arrayList->inicio->tamanho) return 0;
	return 1;
}

int remove_arrayList(ArrayList *arrayList, int pos){
	if(!arrayList) return INVALID_LIST;
	NO *no = arrayList->inicio;
	NO *follow;
	int i, cont = 0;
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
				for(i = pos; i < no->tamanho; i++){
					no->elemento[i]->item = no->elemento[i + 1]->item;
					no->elemento[i]->chave = no->elemento[i + 1]->chave;
				}
				if(pos != no->tamanho) free(no->elemento[i]);

			}
			return SUCCESS;
		}
		else{
			return INVALID_KEY;
		}
	}
	return SUCCESS;
}

void sort(NO *no, int tam){
	int troca=1;
	int i, j;
	ITEM *aux;
	for (i=0; (i<tam-1) && troca; i++) {
		troca=0;
		for (j=0; j<tam-i -1; j++)
			if (no->elemento[j]->chave > no->elemento[j+1]->chave) {
				troca=1;
				aux=no->elemento[j];
				no->elemento[j]=no->elemento[j+1];
				no->elemento[j+1]=aux;
			}
	}
}

//Foi implementado o bubble sort pois os itens estao praticamente ordenados e estao proximos
int set_arrayList(ArrayList *arrayList, int pos, int chave, int item){
	if(!arrayList) return INVALID_LIST;
	NO *no = arrayList->inicio;
	int cont = 0;
	while(1){	
		if(pos >= no->tamanho && no->proximo != NULL){
			cont = no->tamanho - 1;
			no = no->proximo;
		}
		else if(pos < no->tamanho){
			no->elemento[pos - cont]->item = item;
			no->elemento[pos - cont]->chave = chave;
			sort(no, no->tamanho);
			return SUCCESS;
		}
		else{
			return INVALID_POS;
		}
	}
	return SUCCESS;
}

int size_arrayList(ArrayList *arrayList){
	NO *no = arrayList->inicio;
	int size = 0;
	while(no){
		size += no->tamanho;
		no = no->proximo;
	}
	return size;
}

ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex,int endIndex){
	if(!arrayList) return (ArrayList *) INVALID_LIST;
	int i;
	NO *no = arrayList->inicio;
	ArrayList *new = new_arrayList();
	while(1){	
		if(beginIndex >= no->tamanho && no->proximo != NULL){
			no = no->proximo;
		}
		else if(beginIndex < no->tamanho){
			for(i = beginIndex; i < endIndex; i++){
				add_arrayList(new, get_Item(arrayList,i)->chave, get_Item(arrayList,i)->item);
			}
			print_arrayList(new);
			return new;
		}
		else{
			return (ArrayList *) INVALID_POS;
		}
	}
}

int destruct_arrayList(ArrayList **arrayList){
	NO **no = &((*arrayList)->inicio);
	NO **aux;
	while((*no)->proximo){
		aux = no;
		no = &((*no)->proximo);
		free(*aux);
	}
	free(*no);
	free(*arrayList);
	return SUCCESS;
}

void print_arrayList(ArrayList *arrayList){
	NO *no = arrayList->inicio;
	int i;
	int flag = 0;
	int cont = 0;
	for(i = 0; !flag; i++, cont++){	
		if(cont == no->tamanho && no->proximo != NULL){
			no = no->proximo;
			cont = 0;
			printf("\n\n");
		}
		else if(cont == no->tamanho && no->proximo == NULL){
			flag = 1;
		}
		if(cont < no->tamanho){
			printf("%d: ", i);
			printf("%d/%d\n", no->elemento[cont]->chave, no->elemento[cont]->item);
		}
	}
	printf("\n\n");
}
