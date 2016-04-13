#include <stdio.h>
#include <stdlib.h>

// Setando a lista.
typedef struct lista {
	int info;
	struct lista *prox;
} Lista;

// Função que inicia o head com valor NULL.
Lista *inicializa(void) {
	return NULL;
}

// Função que insere um elemento na lista.
Lista *insere(Lista *l, int i) {
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	novo -> info = i;
	novo -> prox = l;
	return novo;
}

// Função que imprime a lista toda.
 void imprime(Lista *l) {
	Lista *p;
	for(p=l; p!=NULL; p = p->prox) printf("info = %d\n", p->info);
} 

// Imprime a lista de modo recursivo.
/* void imprime_rec (Lista *l) {
	Lista *p = l;
	if(vazia(l)) return;
	printf("info: %d\n",p->info);
	imprime_rec(p->prox);
} */

// Função que retorna se a lista está vazia ou não.
int vazia(Lista *l) {
	if(l = NULL) return 1;
	else return 0;
}

// Função que busca um elemento na lista.
Lista *busca(Lista *l, int v) {
	Lista *p;
	for(p=l; p!=NULL; p=p->prox) if(p->info == v)return p;
	return NULL;
}

// Função que retira um elemento da lista e depois libera o espaço do elemento.
/* Lista *retira(Lista *l, int v) {
	Lista *ant = NULL;
	Lista *p = l;
	
	while(p != NULL && p->info != v){
		ant = p;
		p = p->prox;
	}
	
	if(p == NULL) return l;
	
	if(ant == NULL) l = p->prox;
	else ant->prox =  p->prox;
	
	free(p);
	return l;
} */

// Função retira recusivamente.
Lista *retira_rec(Lista *l, int v) {
	if(vazia(l)) return l;
	
	if(l->info == v) {
		Lista *t = l;
		l = l->prox;
		free(t);
	}
	else l->prox = retira_rec(l->prox, v);
	return l;
}

int tamanho(Lista *l) {
	int tam = 0;
	Lista *p;
	for(p = l; p!=NULL; p = l->prox) tam++;
	return tam;
}

// Faz uma segunda lista indêntica a atual.
Lista *copia(Lista *l){
	Lista *l2;
//	l2 = inicializa();
	Lista *p;
	for(p=l; p!=NULL; p=l->prox) {
		l2 = insere(l2, p->info);
	}
}

int igual(Lista *l, Lista *l2) {
// Verifica qual lista é maior para usar como base do for.	
	Lista *aux;
	Lista *aux2;
	
	if(tamanho(l) > tamanho(l2)) {
		aux = l;
		aux2 = l2;
	}
	else {
		aux = l2;
		aux2 = l;
	}
	Lista *p;
	for(p=aux; p!=NULL; p = aux->prox) {
// Verifica se todas as infos são iguais, caso uma seja diferente ele já retorna falso.	
		if(aux2 != NULL)
			if(aux != aux2) return 1;
		else return 1;
	}
	return 0; // Se o for redar sem retornar nada, a lista 2 é igual a lista 1.
}

// Função que termina a lista, liberando todo o espaço da própria.
/* void libera(Lista *l) {
	Lista *p = l;
	while(p != NULL) {
		Lista *t = p-> prox;
		free(p);
		p = t;
	}
} */

// Função libera lista recusivamente.
void libera_rec(Lista* l) {
	if(!vazia(l)) {
		libera_rec(l->prox);
		free(l);
	}
}


int main (void) {
	Lista *l;
	l = inicializa();
	l = insere(l, 23);
	l = insere(l, 45);
	l = insere(l, 56);
	l = insere(l, 78);
//	imprime(l);
	imprime(l);
	system("pause");
// copia l e imprime a copia
	Lista *l2;
	l2 = inicializa();
	l2 = copia(l);
	printf("\n\n");
	imprime(l2);
// compara se l e l2 são iguais.
	if(igual(l, l2) == 0) printf("As listas l e l2 são iguais.");
	else ("As listas l e l2 são diferentes.");
	system("pause");
	l = retira_rec(l, 78);
//	imprime(l);
	imprime(l);
// compara se l e l2 são iguais.
	if(igual(l, l2) == 0) printf("As listas l e l2 são iguais.");
	else ("As listas l e l2 são diferentes.");
	system("pause");
	l = retira_rec(l, 45);
//	imprime(l);
	imprime(l);
	libera_rec(l);
	libera_rec(l2);
	return 0;
}
	 
