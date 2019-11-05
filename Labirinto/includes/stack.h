#ifndef _STACK_H_
#define _STACK_H_
struct stack_element {
	int *elem;
	struct stack_element *next;
};
typedef struct stack_element STACK_ELEMENT; 

struct stack {
	struct stack_element *top;
	int counter;
};
typedef struct stack STACK; 

STACK *create_stack();
STACK_ELEMENT *push_stack_elem(STACK *);
int free_stack(STACK *);
#endif
