#include <stdlib.h>
#include <stdio.h>

typedef struct _No{
    int info;
    struct _No *esq;
    struct _No *dir;
} No;

void criarArvore(No **Raiz){
    *Raiz = NULL;
}

void inserir(No **Raiz, int info){
    if(*Raiz == NULL){
        *Raiz = (No *) malloc(sizeof(No));
        (*Raiz)->esq = NULL;
        (*Raiz)->dir = NULL;
        (*Raiz)->info = info;
    }else{
        if(info < (*Raiz)->info)
            inserir(&(*Raiz)->esq, info);
        if(info > (*Raiz)->info)
            inserir(&(*Raiz)->dir, info);
    }
}

No *MaiorDireita(No **no){
    if((*no)->dir != NULL) 
       return MaiorDireita(&(*no)->dir);
    else{
       No *aux = *no;
       if((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->esq;
       else
          *no = NULL;
       return aux;
       }
}
 
/* No *MenorEsquerda(No **no){
    if((*no)->esq != NULL) 
       return MenorEsquerda(&(*no)->esq);
    else{
       No *aux = *no; 
       if((*no)->dir != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *no = (*no)->dir;
       else
          *no = NULL;
       return aux;
       }
} */
 
void remover(No **Raiz, int info){
    if(*Raiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Numero nao existe na arvore!");
       //getch();
       return;
    }
    if(info < (*Raiz)->info)
       remover(&(*Raiz)->esq, info);
    else 
       if(info > (*Raiz)->info)
          remover(&(*Raiz)->dir, info);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          No *aux = *Raiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if (((*Raiz)->esq == NULL) && ((*Raiz)->dir == NULL)){         // se nao houver filhos...
                free(aux);
                (*Raiz) = NULL; 
               }
          else{     // so tem o filho da direita
             if ((*Raiz)->esq == NULL){
                (*Raiz) = (*Raiz)->dir;
                aux->dir = NULL;
                free(aux); aux = NULL;
                }
             else{            //so tem filho da esquerda
                if ((*Raiz)->dir == NULL){
                    (*Raiz) = (*Raiz)->esq;
                    aux->esq = NULL;
                    free(aux); aux = NULL;
                    }
                else {       //Escolhi fazer o maior filho direito da subarvore esquerda.
                   		aux = MaiorDireita(&(*Raiz)->esq); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                   		aux->esq = (*Raiz)->esq;          //        pAux = MenorEsquerda(&(*pRaiz)->direita);
                   		aux->dir = (*Raiz)->dir;
                   		(*Raiz)->esq = (*Raiz)->dir = NULL;
                   		free((*Raiz));  
                   		*Raiz = aux;  
                   		aux = NULL;   
                    }
                }
             }
          }
}

void exibirEmOrdem(No *Raiz){
    if(Raiz != NULL){
        exibirEmOrdem(Raiz->esq);
        printf("%d ", Raiz->info);
        exibirEmOrdem(Raiz->dir);
    }
}

void exibirPreOrdem(No *Raiz){
    if(Raiz != NULL){
        printf("%d ", Raiz->info);
        exibirPreOrdem(Raiz->esq);
        exibirPreOrdem(Raiz->dir);
    }
}

void exibirPosOrdem(No *Raiz){
    if(Raiz != NULL){
        exibirPosOrdem(Raiz->esq);
        exibirPosOrdem(Raiz->dir);
        printf("%d ", Raiz->info);
    }
}

int contarNos(No *Raiz){
   if(Raiz == NULL)
        return 0;
   else
        return 1 + contarNos(Raiz->esq) + contarNos(Raiz->dir);
}

int contarFolhas(No *Raiz){
   if(Raiz == NULL)
        return 0;
   if(Raiz->esq == NULL && Raiz->dir == NULL)
        return 1;
   return contarFolhas(Raiz->esq) + contarFolhas(Raiz->dir);
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura(No *Raiz){
   if((Raiz == NULL) || (Raiz->esq == NULL && Raiz->dir == NULL))
       return 0;
   else
       return 1 + maior(altura(Raiz->esq), altura(Raiz->dir));
}

int main(){

	int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;
	No **Raiz;
		
	criarArvore(Raiz);
	for(i=0; i<10; i++)
		inserir(Raiz, vet[i]);
			
	printf("\nPré-Ordem: ");
	exibirPreOrdem(*Raiz);
	
	printf("\nPós-Ordem: ");
	exibirPosOrdem(*Raiz);
	
	printf("\nEm Ordem: ");
	exibirEmOrdem(*Raiz);
	
	printf("\nAltura: %d", altura(*Raiz));
	
	printf("\nFolhas: %d", contarFolhas(*Raiz));
	
	printf("\nNós: %d", contarNos(*Raiz));	
	
	remover(Raiz, 5);
	printf("\n\nRemovido o 5: ");
	
	printf("\nPré-Ordem: ");
	exibirPreOrdem(*Raiz);
	
	printf("\nPós-Ordem: ");
	exibirPosOrdem(*Raiz);
	
	printf("\nEm Ordem: ");
	exibirEmOrdem(*Raiz);
	
	printf("\nAltura: %d", altura(*Raiz));
	
	printf("\nFolhas: %d", contarFolhas(*Raiz));
	
	printf("\nNós: %d", contarNos(*Raiz));
	
	remover(Raiz, 9);
	printf("\n\nRemovido o 9: ");
	
	printf("\nPré-Ordem: ");
	exibirPreOrdem(*Raiz);
	
	printf("\nPós-Ordem: ");
	exibirPosOrdem(*Raiz);
	
	printf("\nEm Ordem: ");
	exibirEmOrdem(*Raiz);
	
	printf("\nAltura: %d", altura(*Raiz));
	
	printf("\nFolhas: %d", contarFolhas(*Raiz));
	
	printf("\nNós: %d", contarNos(*Raiz));
	
	remover(Raiz, 1);
	printf("\n\nRemovido o 1: ");
	
	printf("\nPré-Ordem: ");
	exibirPreOrdem(*Raiz);
	
	printf("\nPós-Ordem: ");
	exibirPosOrdem(*Raiz);
	
	printf("\nEm Ordem: ");
	exibirEmOrdem(*Raiz);
	
	printf("\nAltura: %d", altura(*Raiz));
	
	printf("\nFolhas: %d", contarFolhas(*Raiz));
	
	printf("\nNós: %d", contarNos(*Raiz));
	
	printf("\n");
return 0;
}
