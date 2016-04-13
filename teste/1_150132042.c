/*
João Henrique mat 150132042
Jordan Miranda mat 130045772
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct _no_lista{
  int info;
  struct _no_lista *prox;
  struct _no_lista *ant;
}no_lista;

typedef struct _lista{

  int qtd_elementos;
  struct _no_lista *head;
  struct _no_lista *tail;
}lista;

void insereNo(int elem, lista *l){

     no_lista *percorrer;
     no_lista *novo;

     novo = (no_lista*)malloc(sizeof(no_lista));
     novo->info= elem;


     if(l->qtd_elementos == 0){

     }
     else{
          novo->prox = l->head;
          novo->ant = l->head;

   }
     l->qtd_elementos++;
}



void imprime(lista* l ){
  no_lista* aux = l->head;

  while(aux != NULL){
    printf("valor: %d",aux->info);
    aux = aux->prox;
  }
}



void imprimeListaInverso(lista *l){
    no_lista *percorrer;
    int i = 0;

    percorrer = l->tail;

    while(percorrer != NULL){
        printf("%d\n",percorrer->info);
        percorrer = percorrer->ant;
        i++;
    }
}

int removeNo(int elem,lista *l){

  no_lista *percorrer;
  no_lista *aux;
  int checagem;

  if(l->qtd_elementos == 0){
    printf("ESCOLHA INVALIDA\n");
    return 0;
  }

  percorrer = l->head;
  aux= percorrer->prox;
  if(l->head->info == elem){
    l->head = aux;
    free(percorrer);
    l->qtd_elementos--;
    return 1;
  }
  do{
      if(aux->info == elem){
          percorrer->prox = aux->prox;
          free(aux);
          l->qtd_elementos--;
          return 1;
      }
      printf("ESCOLHA INVALIDA\n");
      return 0;
  }while(aux != NULL);
}

int main(){

      no_lista *elemento;
      lista *l = (lista*) malloc(sizeof(lista)) ;
      l->qtd_elementos = 0;



      insereNo(1,l);
      insereNo(10,l);
      insereNo(1000,l);
      insereNo(2,l);

      imprime(l);




  return 0;



}
