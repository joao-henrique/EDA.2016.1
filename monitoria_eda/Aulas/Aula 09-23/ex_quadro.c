#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
	int valor;
	struct _no *prox;
} Celula;

void insere(int x, Celula *p) {
	Celula *l = (Celula*) malloc(sizeof(Celula));
	Celula *i;
	l -> valor = x;
	l -> prox = p -> prox;
	p -> prox = l;
}

int main() {




return 0;
}
