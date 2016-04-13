#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore {

	int info;
	struct Arvore *sae, *sad;
	
} arvore;

void inserir(arvore **raiz, arvore *no) {

	if (!(*raiz)) {
	
		*raiz = no;
		return;
		
	}
	
	if (no -> info < (*raiz) -> info)
		inserir(&(*raiz) -> sae, no);
	else
		inserir(&(*raiz) -> sad, no);
		
}

void em_ordem(arvore *raiz) {

	if (raiz -> sae)
		em_ordem(raiz -> sae);
	printf("%d ", raiz -> info);
	if (raiz -> sad)
		em_ordem(raiz -> sad);
		
}

void pre_ordem(arvore *raiz) {

	printf("%d ", raiz -> info);
	if (raiz -> sae)
		pre_ordem(raiz -> sae);
	if (raiz -> sad)
		pre_ordem(raiz -> sad);
		
}

	void pos_ordem(arvore *raiz) {

	if (raiz -> sae)
		pos_ordem(raiz -> sae);
	if (raiz -> sad)
		pos_ordem(raiz -> sad);
	printf("%d ", raiz -> info);
	
}

int num_nos(arvore *raiz) {

	int i = 1;
	
	if (!raiz)
		return 0;
		
	if (raiz -> sae)
		i += num_nos(raiz -> sae);
		
	if (raiz -> sad)
		i += num_nos(raiz -> sad);
		
	return i;
	
}

int soma_nos(arvore *raiz) {

	int soma = 0;
	
	if (!raiz)
		return 0;
	
	if (raiz -> sae)
		soma += soma_nos(raiz -> sae);
		
	if (raiz -> sad)
		soma += soma_nos(raiz -> sad);
		
	return soma + raiz -> info;

}

int profundidade(arvore *raiz) {

	int pe, pd;
	pe = pd = 1;
	
	if (!raiz)
		return 0;
	
	if (raiz -> sae)
		pe += profundidade(raiz -> sae);
	if (raiz -> sad)
		pd += profundidade(raiz -> sad);
		
	if (pe > pd)
		return pe;
	
	return pd;

}
		

int main() {

	int informacao, i, nos, soma, prof;
	arvore *no, *raiz;
	
	raiz = NULL;
	
	do {
	
		no = (arvore*) malloc(sizeof(arvore));
		no -> sad = NULL;
		no -> sae = NULL;
		scanf("%d", &informacao);
		if (informacao <= 0)
			break;
		no -> info = informacao;
		inserir(&raiz, no);
		
	} while (informacao > 0);
	
	printf("em ordem: ");
	em_ordem(raiz);
	printf("\n");
	printf("pre ordem: ");
	pre_ordem(raiz);
	printf("\n");
	printf("pos ordem: ");
	pos_ordem(raiz);
	printf("\n");
	nos = num_nos(raiz);
	printf("nos: %d\n", nos);
	soma = soma_nos(raiz);
	printf("soma: %d\n", soma);
	prof = profundidade(raiz);
	printf("profundidade: %d\n", prof);
	
	return 0;

}
