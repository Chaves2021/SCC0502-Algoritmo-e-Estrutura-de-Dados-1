#include <array_List.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


int main(void){
	int a =1;
	int c =3;
	int d =4;
	int e =5;

	ArrayList *my = new_arrayList();

	add_arrayList(my, 2, (void *) &a);
	
	add_arrayList(my, 10, (void *) &c);

	add_arrayList(my, 7, (void *) &d);
	
	add_arrayList(my, 2, (void *) &e);

	print_arrayList(my);

	int f = 45;   
	set_arrayList(my, 0, (void *) &f, 99);

	print_arrayList(my);
	return 0;
}