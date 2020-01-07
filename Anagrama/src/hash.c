#include <stdlib.h>
#include <hash.h>

HASH_TABLE *hash_create(){
	HASH_TABLE *h = (HASH_TABLE *) calloc(1, sizeof(HASH_TABLE));
	return h;
}
