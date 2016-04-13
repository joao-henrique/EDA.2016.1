#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Pessoa {
  int cpf;
  char nome[20];
  int idade;
  struct Pessoa *proximo;
};

typedef struct Pessoa Aluno;


Aluno* criar(){

  return;
}



void leia_string(char *nome){
  int c;
   c = getchar();
   if (c == '\n'){
     c = getchar();
   }
   while(c != '\n'){
     (*nome) = c;
     c = getchar();
     nome++;
   }
  // (*nome) = '\n';
}

void exibir_struct(Aluno *aluno){
  printf("\n");
  printf("Aluno: %s\n", aluno->nome);
  printf("CPF: %d\n", aluno->cpf);
  printf("Idade: %d\n", aluno->idade);
  printf("\n");
}


Aluno* inserir(Aluno* alunoLista, int cpf , int idade){

     Aluno* aux;

     Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
     printf("Informe o nome:");
     leia_string(aluno->nome);
     aluno->idade = idade;
     aluno->cpf = cpf;
     aux = alunoLista;
     aluno->proximo = alunoLista->proximo;
     aux->proximo = aluno;

}


Aluno* inserir_ordenado(Aluno* alunoLista,int cpf, int idade){

   Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->cpf = cpf;
    aluno->idade = idade;
    aluno->proximo = NULL;

   Aluno* ant = NULL;
   Aluno* aux = alunoLista;

   printf("\n");

   while(aux != NULL && aux->cpf < cpf){
      printf("1 Loop\n");
      printf("\n");
     ant = aux;
     aux =  aux->proximo;
   }

   if (ant == NULL){
     printf("\n");
     printf("2 ant nUll \n");
     aluno->proximo = aux;
     aux = aluno;
   }else{
     aluno->proximo = ant->proximo;
     printf("\n");
     printf("3 else\n");
     ant->proximo = aluno;
   }
   printf("\n");
   printf("4 saida \n");

}




void exibir_lista(Aluno* listaAluno){
  Aluno* aux;

  for (aux = listaAluno; aux !=NULL; aux = aux->proximo) {
    exibir_struct(aux);
  }


}

void exibirRec(Aluno* lista){

  if(lista == NULL)
    return;
    exibir_struct(lista);
    exibirRec(lista->proximo);
}








Aluno* busca(Aluno* alunoLista, int cpf){

  Aluno* aux;
  for (aux = alunoLista; aux !=NULL; aux = aux->proximo) {
        if(aux->cpf == cpf){
        exibir_struct(aux);
          return aux;
      }
      return NULL;
    }
}



Aluno* retirar(Aluno* alunolista, int cpf){

  Aluno* ant;
  Aluno* aux = alunolista;

    while(aux != NULL && aux->cpf != cpf){
      ant = aux;
      aux = aux->proximo;
    }

    if (ant == NULL) {
      return alunolista;
    }

    if (ant == NULL){
      alunolista = aux->proximo;
    }else{
      ant->proximo = aux->proximo;
    }

    free(aux);
    return alunolista;
}




int main(){
      Aluno* lista = NULL;

    int x,aux;

    do{

        printf("1 - Para Inserir\n");
        printf("2 - Para Listar\n");
        printf("3 - Para Retirar um elemento\n ");

        printf("Informe uma opção:\n ");
        scanf("%d", &x);
        if(x==1){
          printf("Informe o CPF\n ");
          scanf("%d", &aux);
          lista = inserir_ordenado(lista,aux,10);

        }
        if(x ==2 ){
            exibirRec(lista);
        }
        if(x == 3){

          printf("Informe o CPF \n");
          scanf("%d", &aux);

          lista = retirar(lista,aux);

        }

    }while(x<5);


return 0;
}
