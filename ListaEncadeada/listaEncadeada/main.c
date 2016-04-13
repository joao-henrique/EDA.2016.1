#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Lista de coisas que devo ter atenção:
 - Criação da struct
 - Passagem da struct por referência
 - Método de leitura de string********(vc perdeu muito tempo com isso )
*/

struct Aluno{
//  char nome[50];
  int matricula;
  struct Aluno *proximo;
//  struct Aluno *anterior;
};

typedef struct Aluno Aluno;
//Essa função é excelente
void leia_string(char *s) {
  int c;
  c = getchar();

  if (c =='\n') {
       c =getchar();
    }

  while (c!='\n') {
      (*s) = c;
      c = getchar();
       s++;
    }
      (*s) = '\0';
  }


void leia_struct (Aluno *aluno){
    printf("Informe a matricula:\n");
    scanf("%d", &aluno->matricula);
  //  printf("Informe o nome:\n");
//    leia_string(aluno->nome);
}

void exibir_struct(Aluno *aluno){
    printf("\n");
  //  printf("Aluno: %s\n", aluno->nome );
    printf("Matricula: %d\n", aluno->matricula );
    printf("\n");
}

void exibir_lista(Aluno* lista){

  Aluno* l ;
  for (l = lista; l !=NULL; l = l->proximo) {
      printf ("matricula %d\n : ", l->matricula);
  }

}



Aluno* insere(Aluno* alunoLista, int mat ){
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->matricula = mat;
    aluno->proximo = alunoLista;
}

Aluno* busca(Aluno* lista, int v ){

    Aluno* p;
      for (p = lista; p != NULL;  p= p->proximo ) {
        if (p->matricula == v) {
            return p;
        }
        return NULL;
      }
}

Aluno* remover(Aluno* lista, int mat){

  Aluno* ant = NULL;
  Aluno* aux = lista ;

  while (aux != NULL && aux->matricula != mat) {
    ant = aux;
    aux = aux->proximo;
  }

  if (ant == NULL) {
    return lista;
  }

  if (ant == NULL){
      lista = aux->proximo;
  }else{
      ant->proximo = aux->proximo;
  }
  free(aux);
  return lista;
}


int main(int argc, char const *argv[]) {

     Aluno* l;
     l = (Aluno*) malloc( sizeof(Aluno));

     l = insere(l, 23); /* insere na lista o elemento 23 */
     l = insere(l, 45); /* insere na lista o elemento 45 */
     l = insere(l, 56); /* insere na lista o elemento 56 */
     l = insere(l, 78); /* insere na lista o elemento 78 */
     exibir_lista(l); /* imprimirá: 78 56 45 23 */

  return 0;
}
