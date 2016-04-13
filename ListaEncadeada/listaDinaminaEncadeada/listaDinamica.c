#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct lista {
 int info;
 struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa (void)
  {
    return NULL;
  }

Lista* insere (Lista* l, int i)
  {
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   novo->info = i;
   novo->prox = l;
   return novo;
  }

  void imprime (Lista* l)
  {
   Lista* p; /* variável auxiliar para percorrer a lista */
   for (p = l; p != NULL; p = p->prox)
   printf("info = %d\n", p->info);
  }


  int vazia (Lista* l)
  {
   if (l == NULL)
   return 1;
   else
   return 0;
  }

  Lista* busca (Lista* l, int v)
{
 Lista* p;
 for (p=l; p!=NULL; p=p->prox)
 if (p->info == v)
 return p;
 return NULL; /* não achou o elemento */
}

Lista* retira (Lista* l, int v) {
 Lista* ant = NULL; /* ponteiro para elemento anterior */
 Lista* p = l; /* ponteiro para percorrer a lista*/
 /* procura elemento na lista, guardando anterior */
 while (p != NULL && p->info != v) {
 ant = p;
 p = p->prox;
 }
 /* verifica se achou elemento */
 if (p == NULL)
 return l; /* não achou: retorna lista original */
 /* retira elemento */
 if (ant == NULL) {
 /* retira elemento do inicio */
 l = p->prox;
 }
 else {
 /* retira elemento do meio da lista */
 ant->prox = p->prox;
 }
 free(p);
 return l;
}

void libera (Lista* l)
{
 Lista* p = l;
 while (p != NULL) {
 Lista* t = p->prox; /* guarda referência para o próximo elemento
*/
 free(p); /* libera a memória apontada por p */
 p = t; /* faz p apontar para o próximo */
 }
}

Lista* cria (int v)
{
 Lista* p = (Lista*) malloc(sizeof(Lista));
 p->info = v;
 return p;
}
/* função insere_ordenado: insere elemento em ordem */
Lista* insere_ordenado (Lista* l, int v)
{
 Lista* novo = cria(v); /* cria novo nó */
 Lista* ant = NULL; /* ponteiro para elemento anterior */
 Lista* p = l; /* ponteiro para percorrer a lista*/
 /* procura posição de inserção */
 while (p != NULL && p->info < v) {
 ant = p;
 p = p->prox;
 }
 /* insere elemento */
 if (ant == NULL) { /* insere elemento no início */
 novo->prox = l;
 l = novo;
 }
 else { /* insere elemento no meio da lista */
 novo->prox = ant->prox;
 ant->prox = novo;
 }
 return l;
}


/* Função imprime recursiva */
void imprime_rec (Lista* l)
{
 if (vazia(l))
 return;
 /* imprime primeiro elemento */
 printf("info: %d\n",l->info);
 /* imprime sub-lista */
 imprime_rec(l->prox);
}

/* Função retira recursiva */
Lista* retira_rec (Lista* l, int v)
{
 if (vazia(l))
 return l; /* lista vazia: retorna valor original */
 /* verifica se elemento a ser retirado é o primeiro */
 if (l->info == v) {
 Lista* t = l; /* temporário para poder liberar */
 l = l->prox;
 free(t);
 }
 else {
 /* retira de sub-lista */
 l->prox = retira_rec(l->prox,v);
 }
 return l;
}







int main(){
  Lista* l; /* declara uma lista não iniciada */
  l = inicializa(); /* inicia lista vazia */
  l = insere_ordenado(l, 23); /* insere na lista o elemento 23 */
  l = insere_ordenado(l, 45); /* insere na lista o elemento 45 */
  l = insere_ordenado(l, 56); /* insere na lista o elemento 56 */
  l = insere(l, 78); /* insere na lista o elemento 78 */
  printf("\n");
  imprime(l); /* imprimirá: 78 56 45 23 */
  l = retira(l, 78);
  printf("\n");
  imprime(l); /* imprimirá: 56 45 23 */
  l = retira(l, 45);
  printf("\n");
  imprime(l); /* imprimirá: 56 23 */
  libera(l);
  return 0;

}
