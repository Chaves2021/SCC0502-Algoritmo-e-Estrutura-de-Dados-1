#include <stdio.h>
#include <stdlib.h>
#include <_lib_.h>

void lerInteiro(int *inteiro){
	scanf("%d", inteiro);
}

int and(int inteiro1, int inteiro2){
	return inteiro1 & inteiro2;
}

int or(int inteiro1, int inteiro2){
	return inteiro1 | inteiro2;
}

int xor(int inteiro1, int inteiro2){
	return inteiro1 ^ inteiro2;
}

int complement(int inteiro){
	return ~inteiro;
}

int rightShift(int inteiro){
	return inteiro >> 2;
}

int leftShift(int inteiro){
	return inteiro << 2;
}
