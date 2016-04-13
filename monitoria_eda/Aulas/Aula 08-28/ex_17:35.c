//Leia o primeiro 5 naturais e coloque-os numa lista encadeada com inserção no inicio.

#include <stdlib.h>

#define MAX 5

typedef struct _no {
		int n;
		struct _no *prox;
} no;
