#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int info;
	struct No *prox;
	struct No *ant;
} no;

int main() {
	no *p, *l = NULL, *aux = NULL;
	
	int i, n;
	i = 0;
	while(i<5) {
		scanf("%d", &n);
		p = (no*) malloc(sizeof(no));
		p -> info = n;
		if(aux != NULL) { 
			p -> ant = aux;
			aux = p;
			p -> ant -> prox = p;
		}
		else { 
			aux = p;
			p -> ant = NULL;
			p -> prox = l;
		}
		if(l == NULL)
			l = p;
		i++;
	}
	
	printf("\n");
	
	for(p=l; p!=NULL; p = p->prox) {
		printf("%d ", p -> info);
		aux = p;
	}
	
	printf("\n\n");
	
	for(p=aux; p!=NULL; p = p->ant) printf("%d ", p -> info);
	
	printf("\n\n");
	
return 0;
}
