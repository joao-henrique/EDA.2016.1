#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
	int info;
	struct Pilha *prox;
} pilha;

typedef struct Cabecalho {
	struct Pilha *inilist;
	int nelem;
} cab;

void empilhar(cab *header, int num) {
	pilha *aux = (pilha*) malloc(sizeof(pilha));
	aux -> info = num;
	
	if(header -> nelem == 0) {
		aux -> prox = NULL;
		header -> inilist = aux;
		header -> nelem ++;
		return;
	}
	else {
		aux -> prox = header -> inilist;
		header -> inilist = aux;
		header -> nelem ++;
		return;
	}
}

void desempilhar(cab *header) {
	pilha *aux;
	if(header->nelem == 0) {
		printf("Lista Vazia\n");
		return;
	}
	else if(header -> nelem == 1){
		aux = header -> inilist;
		header -> inilist = NULL;
		free(aux);
		header -> nelem --;
		return;
	}
	else {
		aux = header -> inilist;
		header -> inilist = aux -> prox;
		header -> nelem --;
		free(aux);
		return;
	}

}

void imprimir(cab *header) {
	printf("\n\n");
	if(header->nelem == 0) {
		printf("\nLista Vazia\n");
		return;
	}
	int i;
	pilha *aux = header -> inilist;
	for(i=0; i<header->nelem; i++) {
		printf("%d ", aux->info);
		aux = aux -> prox;
	}
	printf("\n");
}

void limpar(cab *header){
	int i;
	pilha *aux = header -> inilist;
	pilha *aux2;
	
	for(i=0; i<header->nelem; i++) {
		aux2 = aux;
		aux = aux -> prox;
		free(aux2);
	}
	header -> inilist = NULL;
	header -> nelem = 0;
}



int main() {
	int opcao, num;
	
	cab *header = (cab*) malloc(sizeof(cab));
	header -> nelem = 0;
	header -> inilist = NULL;
	
	do {
		printf("\n");
		printf("(1) Empilhar\n(2) Desempilhar\n(3) Limpar\n(4) Mostrar\n(5) Terminar\n");
		scanf("%d", &opcao);
		
		switch(opcao) {
		
			case 1:
				printf("\nInfo: ");
				scanf("%d", &num);
				empilhar(header, num);
				break;
				
			case 2:
				desempilhar(header);
				break;
			
			case 3:
				limpar(header);
				break;
				
			case 4:
				imprimir(header);
				break;
				
			case 5:
				break;
				
			default:
				break;
		}
	
	} while(opcao != 5);	
	


return 0;
}
