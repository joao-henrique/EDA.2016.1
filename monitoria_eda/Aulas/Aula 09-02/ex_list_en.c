#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
	int info;
	struct _no *prox;
//	no *ant;
} no;

no *init_list(no *l, int i) {
	no *novo = (no*) malloc(sizeof(no));
	novo -> info = i;
	novo -> prox = l;
	return novo;
}

void inser_elemen() {


}

void remove_elemen() {


}

void edit_elemen() {


}

void print_list() {


}

int main() {
	no *header;
	no *p;
	int i, choice;
	
	header = p;	
	do {
		printf("O que deseja: \n");
		printf(" (1).			Inicializar a lista.\n");
		printf(" (2).			Inserir um elemento na lista.\n");
		printf(" (3).			Remover um elemento da lista.\n");
		printf(" (4).			Alterar um elemento da lista.\n");
		printf(" (5).			Imprimir a lista.\n");
		printf(" (0).			Finalizar Programa.\n");
		printf("Insira o numero correspondente a opcao: ");
		scanf("%d", &choice);
		switch(choice) {	
			case 1:
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
			
			case 5:
			break;
			
			default:
			break;
		}
	} while(choice != 0);


return 0;
}
