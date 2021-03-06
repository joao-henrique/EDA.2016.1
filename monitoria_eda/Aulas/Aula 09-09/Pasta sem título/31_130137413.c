/* O fiz cheio de printf para me orientar, todos os printf's desnecessários foram comentados, mas servem como orientação do funcionamento do programa. */
#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
	int info;
	struct _no *prox;
	struct _no *ant;
} no;

typedef struct cabecalho {
	struct _no *inilist;
	int nelem;
	struct _no *fimlist;
} cab;

typedef enum boolean {
	true = 1, false = 0
} bool;

cab *inicializa() {
	cab *p;
	p = (cab*) malloc(sizeof(cab));
	p -> inilist = NULL;
	p -> nelem = 0;
	p -> fimlist = NULL;
	return p;
}

void ordena_lista(cab *l, no *p) {
	int i;
	no *aux = l->inilist;
	for(i = 0; i<l->nelem; i++) {
		if(l->nelem == 1){ 
			if(p->info < aux->info) {
				aux->ant = p;
				p -> prox = aux;
				l -> inilist = p;
				l -> nelem += 1;
				/*printf("\nAluno Adicionado.\n");*/
				return;
			}
			else {
				aux -> prox = p;
				p -> ant = aux;
				l -> fimlist = p;
				l -> nelem += 1;
				/*printf("\nAluno Adicionado.\n");*/
				return;
			}
		}
		else if((p->info > aux->info) && (aux->prox == NULL)) {
			p -> ant = aux;
			p -> prox = NULL;
			aux -> prox = p;
			l -> fimlist = p;
			l -> nelem += 1;
			/*printf("\nAluno Adicionado.\n");*/
			return;
		}
		else if((p->info > aux->info) && (aux->prox != NULL) && (p->info < aux->prox->info)) {
			p -> ant = aux;
			p -> prox = aux->prox;
			aux -> prox = p;
			p -> prox -> ant = p;
			l -> nelem += 1;
			/*printf("\nAluno Adicionado.\n");*/
			return;
		}
		else if((p->info < aux->info) && (aux->ant == NULL)) {
			p -> prox = aux;
			p -> ant = NULL;
			aux -> ant = p;
			l -> inilist = p;
			l -> nelem += 1;
			/*printf("\nAluno Adicionado.\n");*/
			return;
		}
		aux = aux->prox;
	} /* fim for */
	/*printf("\nAconteceu algum erro na ordenacao. Aluno não adicionado.\n");*/
}

void insere(cab *l, int num) {
	no *p;
	p = (no*) malloc(sizeof(no));
	p->info = num;
	if(l->nelem != 0)
		ordena_lista(l, p);
	else {
		p->prox = NULL;
		p->ant = NULL;
		l -> inilist = p;
		l -> fimlist = p;
		l -> nelem = 1;
		/*printf("\nAluno Adicionado.\n");*/
	}
}

void retira_elemento(cab *l, int num) {
	int i;
	no *aux = l->inilist;
	
	for(i=0; i<l->nelem; i++) {
		if(aux->info == num) {
			if(aux -> ant == NULL) {
				l -> inilist = aux -> prox;
				aux -> prox -> ant = NULL;
				free(aux);
				l -> nelem -= 1;
				printf("ALUNO RETIRADO\n");
				return;
			}
			else if(aux->prox == NULL) {
				l -> fimlist = aux -> ant;
				aux -> ant -> prox = NULL;
				free(aux);
				l -> nelem -= 1;
				printf("ALUNO RETIRADO\n");
				return;
			}
			else {
				aux -> prox -> ant = aux -> ant;
				aux -> ant -> prox = aux -> prox;
				free(aux);
				l -> nelem -= 1;
				printf("ALUNO RETIRADO\n");
				return;
			}
		}
		aux = aux->prox;
	}
	printf("ALUNO NAO ENCONTRADO\n");
}

void busca_elemento(cab *l, int num, bool posicao) {
	int i, j = l->nelem;
	no *aux = l->inilist;
	
	for(i=0; i<l->nelem; i++) {
		if(aux -> info == num) {
			if(posicao) {
			/*	printf("\nAluno encontrado: \n");
				printf("Aluno %d encontra-se na posicao %d da lista.\n", num, i+1);*/
				return;
			}
			else {
				/*printf("\nAluno encontrado: \n");
				printf("Aluno %d encontra-se na posicao %d da lista.\n", num, j);*/
				return;
			}
		}
		j--;
		aux = aux->prox;
	}
	/*printf("\nAluno não encontrado.\n");*/
}

void imprimir(cab *l, bool posicao) {
	int i;
	
	if(posicao) {
		no *aux = l->inilist;
		for(i=0; i<l->nelem; i++) {
			printf("%d ", aux->info);
			aux = aux->prox;
		}
	}
	else {
		no *aux = l->fimlist;
		for(i=0; i<l->nelem; i++) {
			printf("%d ", aux->info);
			aux = aux->ant;
		}
	}
	printf("\n");
}

void liberar_lista(cab *l) {
	int i;
	no *aux = l->inilist;
	
	for(i=0; i<(l->nelem-1); i++) {
			aux = aux->prox;
			free(aux->ant);
	}
	free(aux);
	free(l);
	/*printf("\nPrograma Finalizado.\n");*/
}

int main() {

	cab *l;
	int menu, num;
	bool posicao = true;
	
	l = inicializa();
	do {
	/*	printf("\n1) Adicionar um aluno na lista: \n");
		printf("2) Retirar aluno da lista: \n");
		printf("3) Achar aluno na lista: \n");
		printf("4) Imprimir a lista: \n");
		printf("5) Inverter lista [Crescente/Decrescente]: \n");
		printf("6) Liberar lista e terminar programa.\n");
		printf("Escolha: "); */
		scanf("%d", &menu);
		switch(menu) {
			case 1:
			/*	printf("\n\nInsira o numero da matricula do aluno: "); */
				scanf("%d", &num);
				insere(l, num);
				break;
				
			case 2:
			/*	printf("\n\n2) Digite a matricula do aluno a ser retirado: "); */
				scanf("%d", &num);
				retira_elemento(l, num);
				break;
				
			case 3:
			/*	printf("\n\nDigite o numero da matricula do aluno que deseja encontrar na lista: "); */
				scanf("%d", &num);
				busca_elemento(l, num, posicao);
				break;
				
			case 4:
				imprimir(l, posicao);
				break;
				
			case 5:
				if(posicao) {
					posicao = false;
					/*printf("\nLista invertida para decrescente.\n");*/
				}
				else {
					posicao = true;
					/*printf("\nLista invertida para crescente.\n"); */
				}
				break;
			
			case 6:
				liberar_lista(l);
				break;
				
			default:
				/*printf("\n\nOpcao Invalida.\n\n"); */
				break;
		}
	} while(menu!=6);

return 0;
}
