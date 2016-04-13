
#include <stdio.h>
#include <stdlib.h>

typedef struct _arv {
	int info;
	struct _arv *sae;
	struct _arv *sad;
} arv;

void insere(arv **raiz, arv *no) {
		*raiz = no;
	if(!(*raiz)) {
		return;
	}
	else {
		if(no->info < (*raiz)->info)
			insere(&(*raiz)->sae, no);
		else
			insere(&(*raiz)->sad, no);
	}
}

void preOrdem(arv *raiz) {
	printf("%d ", raiz->info);
	if(raiz->sae)
		preOrdem(raiz->sae);
	if(raiz->sad)
		preOrdem(raiz->sad);
}

void emOrdem(arv *raiz) {
	if(raiz->sae)
		emOrdem(raiz->sae);
	printf("%d ", raiz->info);
	if(raiz->sad)
		emOrdem(raiz->sad);	
}

void posOrdem(arv *raiz) {
	if(raiz->sae)
		posOrdem(raiz->sae);
	if(raiz->sad)
		posOrdem(raiz->sad);
	printf("%d ", raiz->info);
}

int profundidade(arv *raiz) {
	int pe, pd;
	
	pe = pd = 1;
	
	if(!raiz)
		return 0;
	
	if(raiz -> sae)
		pe += profundidade(raiz->sae);
	if(raiz -> sad)
		pd += profundidade(raiz->sad);
		
	if(pe > pd)
		return pe;
	
	return pd;
}

int num_nos(arv *raiz) {
	int nos = 1;
	
	if(!raiz)
		return 0;
	
	if(raiz->sae)
		nos += num_nos(raiz->sae);
	
	if(raiz->sad)
		nos += num_nos(raiz->sad);
		
	return nos;
}

int main() {
	int info;
	arv *raiz, *no;
	
	raiz = NULL;
	
	do {
		scanf("%d", &info);
		if(info != -1) {
			no = (arv*) malloc(sizeof(arv));
			no->sae = no->sad = NULL;
			no->info = info;
			insere(&raiz, no);
		}
	} while(info != -1);

	printf("Pŕe-Ordem: ");
	preOrdem(raiz);
	printf("\nEm-Ordem: ");
	emOrdem(raiz);
	printf("\nPós-Ordem: ");
	posOrdem(raiz);
	printf("\nProfundidade: %d", profundidade(raiz));
	printf("\nNós: %d", num_nos(raiz));
	printf("\n");	
return 0;
}
