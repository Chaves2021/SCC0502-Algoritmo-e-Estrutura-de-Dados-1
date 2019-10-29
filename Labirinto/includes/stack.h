#ifndef _STACK_H_
#define _STACK_H_
struct stack_element {
	void *elem;
	struct stack_element *next;
};

struct stack {
	struct stack_element *top;
	int counter;
};

#endif
