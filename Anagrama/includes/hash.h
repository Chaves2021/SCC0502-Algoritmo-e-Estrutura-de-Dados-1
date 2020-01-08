#ifndef _HASH_
#define _HASH_

struct hash_elem{
	char letter;
	int value; //value that represents each letter and can only be prime
	int frequency; //frequency that letter appears
	struct hash_elem *next; //the next hash elem with same index
};
typedef struct hash_elem HASH_ELEM;

struct hash_table{
	HASH_ELEM **hash_elem; //the element of the hash table
	int size;
};
typedef struct hash_table HASH_TABLE;

//function to create the hash table
HASH_TABLE *hash_create();
//function to add an elem into the hash table
int hash_add(HASH_TABLE *, int);
//function to search an elem from the hash table
int hash_search(HASH_TABLE *, int);
//function to remove an elem from the hash table
int hash_remove(HASH_TABLE *, int);
//function to destroy the hash table
int hash_destroy(HASH_TABLE *);

#endif
