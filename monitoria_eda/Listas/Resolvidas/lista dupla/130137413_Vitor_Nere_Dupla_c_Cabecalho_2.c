#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
	int info;
	struct _no *prox;
	struct _no *ant;
} no;

typedef struct _cabecalho {
	struct _no *inilist;
	int nelem;
	struct _no *fimlist;
} cab;

int main() {
	no *p, *aux = NULL;
	cab *l;
	int i, n;

	l = malloc(sizeof(cab));
	l -> inilist = NULL;
	l -> nelem = 0;
	l -> fimlist = NULL;
	i = 0;
	while(i<5) {
		scanf("%d", &n);
		p = (no*) malloc(sizeof(no));
		p -> info = n;
		p -> prox = NULL;

		if(l->nelem != 0) {
			p -> ant = aux;
			aux -> prox = p;
			aux = p;
		}

		else {
			p -> ant = NULL;
			l -> inilist = p;
			aux = p;
		}
		l -> fimlist = p;
		l -> nelem += 1;
	i++;
	}

	printf("\n");

	for(p=l->inilist; p!=NULL; p = p->prox) {
		printf("%d ", p -> info);
	}

	printf("\n\n");

	for(p=l->fimlist; p!=NULL; p = p->ant) printf("%d ", p -> info);

	printf("\n\n");

return 0;
}
