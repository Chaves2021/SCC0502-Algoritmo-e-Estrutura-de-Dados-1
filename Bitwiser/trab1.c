#include <stdio.h>
#include <stdlib.h>
#include <_lib_.h>

int main(void){
	int a, b;
	lerInteiro(&a);
	lerInteiro(&b);
	printf("%d\n", and(a, b));
	printf("%d\n", or(a, b));
	printf("%d\n", xor(a, b));
	printf("%d\n", complement(a));
	printf("%d\n", complement(b));
	printf("%d\n", rightShift(a));
	printf("%d\n", leftShift(b));
	return 0;
}
