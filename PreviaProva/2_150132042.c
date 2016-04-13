#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno{
  char matricula[10];
  char nome[50];
  int   p1,p2,p3;
  float media;
  char result[3];
  struct aluno *prox;
};
typedef struct aluno Aluno;


void leia_string(char *nome){

  int c;
  c = getchar();
  if(c == '\n'){
    c = getchar();
  }
  while(c != '\n'){
    (*nome) = c;
    c =getchar();
    nome++;
  }
  (*nome) = '\n';
}

void leia_notas(Aluno* aluno){

    do{
      printf("Informe a nota 1: \n");
      scanf("%d",&aluno->p1);

    }while(aluno->p1 < 0 || aluno->p1 > 100 );
    do{
      printf("Informe a nota 2: \n");
      scanf("%d",&aluno->p2);

    }while(aluno->p2 < 0 || aluno->p2 > 100 );
    do{
      printf("Informe a nota 3: \n");
      scanf("%d",&aluno->p3);

    }while(aluno->p3 < 0 || aluno->p3 > 100 );
}

void calc_media(Aluno* aluno){

  aluno->media = (aluno->p1 + aluno->p2+ aluno->p3)/3;

  if(aluno->media >= 50)
  {
    strcpy(aluno->result, "APR");
  }else{
    strcpy(aluno->result, "REP");

  }

}


Aluno* inserir_ordenado(Aluno* lista, Aluno* aluno){

  Aluno* ant = NULL;
  Aluno* aux  = lista;

  while (aux != NULL && aux->media > aluno->media) {
      ant = aux;
      aux = aux->prox;
    }
  if (ant == NULL){

    aluno->prox = lista;
    lista = aluno;
  }
  else{
    aluno->prox = ant->prox;
    ant->prox = aluno;
  }

  return lista;
}



Aluno* registrar_aluno(Aluno* lista){

    Aluno* aluno= (Aluno*) malloc(sizeof(Aluno));
    printf("Registrar um novo Aluno \n");
    leia_string(aluno->nome);
    printf("Informe a Matricula: ");
    leia_string(aluno->matricula);
    leia_notas(aluno);
    calc_media(aluno);
    aluno =  inserir_ordenado(lista,aluno);
    return aluno;
}


void imprime(Aluno* lista){

    if(lista == NULL)
      return;

    printf("\nNome: %s",lista->nome);
    printf("\nMatricula: %s",lista->matricula);
    printf("\n Media: %f",lista->media);
    imprime(lista->prox);

  }

int main(){

    Aluno* lista = NULL;
    int opcao;
      do{
          printf("\nSelecione uma opção: \n");
          printf("1 - Inserir um novo aluno \n");
          printf("2 - Listar os aluno\n");
          printf("0 - Sair \n");
          scanf("%d",&opcao);

            if(opcao == 1){
              lista = registrar_aluno(lista);
            }
            if(opcao == 2 ){
              imprime(lista);
            }
      }
      while(opcao!= 0);

  return 0;
}
