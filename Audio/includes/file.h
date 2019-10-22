#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

typedef enum{
	INT,
	CHAR,
	UNSIGNED_CHAR,
	DOUBLE
} TYPE;

void *ler_arquivo(FILE *, TYPE, int *);

#endif
