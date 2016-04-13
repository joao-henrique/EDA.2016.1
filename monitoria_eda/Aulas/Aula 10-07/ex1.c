#include <stdio.h>
#include <stdlib.h>

void imprimi(int ini, int fim, int *fila) {
	int i;
	if(ini > fim) {
		for(i = ini; i<9; i++)
			printf("%d ", fila[i]);
		for(i = 0; i<fim; i++)
			printf("%d ", fila[i]);
	}
	else {
		for(i = ini; i<fim; i++) {
			printf("%d ", fila[i]);
		}
	}
	printf("\n\n");
}

int main() {

	int fila[10];
	int ini;
	int fim;
	int elem;
	int filafim;
	char opcao;

	ini = 0;
	fim = 0;
	filafim = 9;
	
	do {
		opcao = getchar();
		if(opcao == 'I') {
			if(fim == filafim)
				printf("Fila Cheia\n");
			else {
				scanf("%d", &elem);
				if(fim == 9) {
					fila[fim] = elem;
					fim = 0;
				}
				else
					fila[fim++] = elem;
				imprimi(ini, fim, fila);
			}
		}
		else if(opcao == 'R') {
			if(ini == fim)
				printf("Fila Vazia\n");
			else {
				if(ini == 9){
					ini = 0;
				}
					
				else
					ini++;
				if(filafim == 9)
					filafim = 0;
				else
					filafim++;
				imprimi(ini, fim, fila);
			}
		} 
	
	} while(opcao != 'F');

}
