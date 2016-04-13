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
	no *p;
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
		p -> prox = l -> inilist;
		p -> ant = NULL;
		if(l->nelem != 0) 
			l -> inilist -> ant = p;
		else
			l -> fimlist = p;
		l -> inilist = p;
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
