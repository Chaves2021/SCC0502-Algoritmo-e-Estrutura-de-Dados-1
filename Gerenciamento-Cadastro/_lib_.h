#ifndef _lib_
#define _lib_
struct REGISTER_ELEM{
	char *first_name;
	char *last_name;
	char *cpf;
	char *tel;
	struct REGISTER_ELEM *next;
	struct REGISTER_ELEM *prev;
};

struct REGISTER{
	struct REGISTER_ELEM *first; 
	struct REGISTER_ELEM *last; 
	int count;
};

#define SUCCESS         0 
#define INVALID_LIST   -1
#define REMOVE_ERROR   -2
#define GET_ERROR      -3
#define INVALID_POS    -4
#define ELEM_NOT_FOUND -5

REGISTER *create_register(void);
int add(REGISTER *, int, char *);
int get_register(REGISTER *, char *);
void dump(REGISTER *);
void remove(REGISTER *, char *);
void exit();

#endif
