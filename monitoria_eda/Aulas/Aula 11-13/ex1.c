#include <stdio.h>
#include <stdlib.h>

typedef struct _Arv {
	char inf;
	struct Arv *esq;
	struct Arv *dir;
} Arv;

Arv* criavazia(char c, Arv *sae, Arv *sad) {
	Arv *p = (Arv*) malloc(sizeof(Arv));
	
	P -> info = c;
	p -> esq = sae;
	p -> dir = sad;
	return p;
}

void imprime(Arv *aux) {
	printf(" %c", p -> info);
	
	if(p->esq != NULL)
		imprime(p->esq);
	if(p->dir !=NULL)
		imprime(p->dir);
}


int main() {
	Arv *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9;
	
	a1 = cria('3', NULL, NULL);
	a2 = cria('6', NULL, NULL);
	a3 = cria()
	a4 = cria()
	a5 = cria()
	a6 = cria()
	a7 = cria()
	a8 = cria()
	a9 = cria()


}
