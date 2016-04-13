#include <stdlib.h>
#include <stdio.h>


struct no {
 int info;
 struct no* anterior;
 struct no* proximo;
};
typedef struct no Lista;



Lista* insere_ordenado(Lista* lista, int v)
{
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  novo->info = v;

  Lista* auxiliar = lista;
  Lista* anterior = NULL;



  while (auxiliar != NULL && auxiliar->info <v ) {
      anterior = auxiliar;
      auxiliar = auxiliar->proximo;
  }

  if (anterior == NULL){
    novo->proximo = lista;
    novo->anterior = NULL;
    lista = novo;
  }else{

    anterior->proximo = novo;
    anterior->anterior = NULL;
    novo->proximo = anterior->proximo->anterior;
  }
return lista;

}


Lista* insereDupla(Lista* lista, int v){

    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    novo->proximo = NULL;


    if(lista == NULL){
        novo->anterior = lista;

        lista = novo;
    }else{
    //  printf("%d\n",lista->anterior->info);
      novo->anterior = lista;
      lista->proximo = novo;
      lista = novo;



    }

    return lista;

    }


Lista* busca (Lista* lista, int v)
  {
     Lista* p;
     for (p=lista; p!=NULL; p=p->proximo)
     if (p->info == v)
     return p;
     return NULL; /* não achou o elemento */
   }



Lista* retira (Lista* l, int v) {

  Lista* p = busca(l,v);
    if (p == NULL)
    return l; /* não achou o elemento: retorna lista inalterada */
 /* retira elemento do encadeamento */
  if (l == p)
    l = p->proximo;
  else
    p->anterior->proximo = p->proximo;

  if (p->proximo != NULL)
    p->proximo->anterior = p->anterior;
    free(p);
    return l;
}

void imprime_rec (Lista* l)
{
 if (l == NULL)
 return;
 /* imprime primeiro elemento */
 printf("info: %d\n",l->info);
 /* imprime sub-lista */
 imprime_rec(l->anterior);
}

void imprime_Tras (Lista* l)
{

   Lista* auxiliar = l;
   Lista* anterior = NULL;



   while (auxiliar != NULL ) {
       anterior = auxiliar;
       auxiliar = auxiliar->anterior;
   }


 printf("info: %d\n",anterior->info);
 /* imprime sub-lista */
 imprime_Tras(anterior->proximo);
}




int main (){

  Lista* lista= NULL;

  lista = insereDupla(lista,444);
  lista = insereDupla(lista,5);
  lista = insereDupla(lista,6);
  lista = insereDupla(lista,4);

  printf("%d\n",lista->anterior->anterior->info);

//
//   lista = insere_ordenado(lista,10);
// //  printf("%d\n",lista->proximo->proximo->info);
//   lista = insere_ordenado(lista,88);
// //  printf("%d\n",lista->proximo->info);
//   lista = insere_ordenado(lista,888);
// //  printf("%d\n",lista->proximo->info);
//   lista = insere_ordenado(lista,888888);
//   printf("%d\n",lista->anterior->info);
//   aux =lista->proximo->proximo->proximo;
// //  printf("%d\n",aux->anterior->info);

  //imprime_Tras(lista);
  imprime_rec(lista);


}
