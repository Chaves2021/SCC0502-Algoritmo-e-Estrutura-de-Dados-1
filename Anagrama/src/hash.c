#include <stdlib.h>
#include <hash.h>
#include <defines.h>

HASH_TABLE *hash_create(){
	HASH_TABLE *h = (HASH_TABLE *) calloc(1, sizeof(HASH_TABLE));
	return h;
}

int hash_add(HASH_TABLE *, int value){
}
