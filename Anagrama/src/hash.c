#include <stdlib.h>
#include <hash.h>
#include <defines.h>

HASH_TABLE *hash_create()
{
	HASH_TABLE *h = (HASH_TABLE *) calloc(1, sizeof(HASH_TABLE));
	return h;
}

int hash_add(HASH_TABLE **table, char letter, int *prime_numbers)
{
	//TODO
	//Includes "Invalid hashtable" in the defines
	if(!table) return INVALID_HASHTABLE;

	int index; //the index of the hash table elem array
	index = (int) letter % M;
	if(table->HASH_ELEM[index])
	{
		if(table->HASH_ELEM[index]->letter == letter) return SUCCESS;
		else
		{
			HASH_ELEM *h = table->HASH_ELEM[index]->next;
			while(h)
			{
				if(h->letter == letter) return SUCCESS;
				else h = h->next;
			}
		}
		//TODO
		//Just create a new hash_elem and link it with the antecessor (according to google, antecessor exists in english)
	}
	//TODO
	//Here needs to create the first hash_elem with this index, a little bit different from the above todo
}
