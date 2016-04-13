#include <stdlib.h>
#include <stdio.h>
#define  MAX_PROCESSOS 5



typedef struct processo Processo;
typedef struct cabecalho Cabecalho;

struct processo{
  int id;
  Processo* prox;
  Processo* ant;
};


struct cabecalho{
    int qtd_elementos;
     Processo *head;
     Processo *tail;
};




void insere(Cabecalho *cabecalho, int v ){

      Processo* novo = (Processo*) malloc( sizeof(Processo) );
      novo->id = v;

       if(cabecalho->qtd_elementos >= MAX_PROCESSOS){
        printf("Limite de processos excedido \n");
        return;
       }

        novo->ant = cabecalho->tail;
        novo->prox = NULL;


      if(cabecalho->qtd_elementos !=0 ){

        cabecalho->tail->prox = novo;
        cabecalho->tail = novo;

      }else{
        cabecalho->tail = novo;
        cabecalho->head = novo;
      }
     cabecalho->qtd_elementos++;
}

void imprimeHead(Processo* processo){
  if(processo == NULL){
      return ;
  }else{
    printf("%d\n",processo->id );
    imprimeHead(processo->prox);
  }
}


void imprimeTail(Processo* processo){

  Processo* percorrer;
  int i;

  percorrer = processo;

  if(processo == NULL){
      return ;
  }else{
    printf("%d\n",processo->id );
    imprimeTail(processo->ant);
  }
}


void remover(Cabecalho* cabecalho, int v)
{
  Processo* percorrer = cabecalho->tail;


  if (cabecalho->qtd_elementos <= 1)
  {
    printf("Retirada não autorizada\n");
    return;
  }

  if(cabecalho->tail->id == v){
      Processo* aux = percorrer;
      percorrer = percorrer->ant;
      free(aux);
  }
  else{
    remover(cabecalho);
  }




}


int main() {

  Cabecalho* cabecalho = (Cabecalho*) malloc(sizeof(Cabecalho));
  insere(cabecalho,5);
  printf("Quant: %d\n",cabecalho->qtd_elementos );
  insere(cabecalho,6);
  printf("Quant: %d\n",cabecalho->qtd_elementos );
  insere(cabecalho,4);
  insere(cabecalho,7);
  insere(cabecalho,9);
  printf("Quant: %d\n",cabecalho->qtd_elementos );
  insere(cabecalho,10);

    printf("\n");
    printf("Primeiro da lista: %d\n",cabecalho->head->id );

    printf("Terceiro da lista: %d\n",cabecalho->head->prox->prox->id);
    printf("Ultimo da Lista: %d\n",cabecalho->tail->id );
    printf("Penultimo da Lista: %d\n",cabecalho->tail->ant->id );
    printf("Antipenultimo da Lista: %d\n",cabecalho->tail->ant->ant->id );

    printf("Ultimo da Lista: %p\n",cabecalho->head->ant );
    printf("\n");
    imprimeHead(cabecalho->head);
    printf("\n");
    imprimeTail(cabecalho->tail);

  return 0;






}
