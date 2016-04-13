#include <stdio.h>
#include <stdlib.h>

typedef struct _lista {
	struct _lista *prox;
	int info;
} li;

typedef struct _cab {
	struct _lista *inilist;
	int nelem;
	struct _lista *fimlist;
} cab;

void insere(cab *cabecalho, int num) {
	li *p = (li*) malloc(sizeof(li));
	p -> info = num;
	p -> prox = cabecalho->inilist;
	if(cabecalho->nelem == 0) {
		cabecalho->inilist = p;
		cabecalho->fimlist = p;
		cabecalho->nelem = 1;
	}
	else {
		cabecalho->fimlist->prox = p;
		cabecalho->fimlist = p;
		cabecalho->nelem ++;
	}
}

void retira(cab *cabecalho) {
	li *p;
	p = cabecalho->inilist;
	cabecalho->inilist = p->prox;
	cabecalho->fimlist->prox = cabecalho->inilist;
	cabecalho->nelem --;
	free(p);
}

void imprime(cab *cabecalho) {
	int i;
	li *p = cabecalho->inilist;
	for(i=0; i<cabecalho->nelem; i++) {
		printf("%d ", p->info);
		p = p->prox;
	}
	printf("\n");
}


int main() {
	li *l = (li*) malloc(sizeof(li));
	cab *cabecalho = (cab*) malloc(sizeof(cab));	
	char opcao;
	int num;

	cabecalho -> inilist = NULL;
	cabecalho -> fimlist = NULL;
	cabecalho -> nelem = 0;
	
	do {
		__fpurge(stdin);
		opcao = getchar();	
		
		if(opcao == 'I') {
			scanf("%d", &num);
			insere(cabecalho, num);
			imprime(cabecalho);
		}
		else if(opcao == 'R') {
			if(cabecalho -> nelem == 0)
				printf("Lista Vazia\n");
			else {
				retira(cabecalho);
				imprime(cabecalho);
			}
		}	
	} while(opcao != 'F');

return 0;
}
