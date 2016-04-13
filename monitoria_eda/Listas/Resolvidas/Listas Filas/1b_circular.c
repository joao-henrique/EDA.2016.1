#include <stdio.h>
#include <stdlib.h>
	
int main() {

	int fila[7], ini, fim, num, i;
	char opcao;
	
	ini = 0;
	fim = 0;
	
	do {
		__fpurge(stdin);
		opcao = getchar();
		
		if(opcao == 'I') {
			scanf("%d", &num);
			if((fim == 7 && ini < 2) || (fim == (ini-1))) {
				printf("Fila Cheia\n\n");
			}
			else {
				if(fim == 7) {
					fim = 0;
				}
				fila[fim++] = num;
				if(fim < ini) {
					for(i = ini; i<7; i++) {
						printf("%d ", fila[i]);
					}
					for(i = 0; i<fim; i++) {
						printf("%d ", fila[i]);
					}
					printf("\n"); 
				}
				else {
					for(i = ini; i<fim; i++) {
						printf("%d ", fila[i]);
					}
					printf("\n");
				}
			}
		}
		else if(opcao == 'R') {
			if(ini == fim) {
				printf("Fila Vazia\n\n");
			}
			else {
				printf("\n%d\n", ini);
				if(ini == 7) {
					ini = 0;
				}
				fila[ini++];
				printf("\n%d\n", ini);
				if(fim < ini) {
					for(i = ini; i<7; i++) {
						printf("%d", fila[i]);
					}
					for(i = 0; i<fim; i++) {
						printf("%d", fila[i]);
					}
					printf("\n"); 
				}
				else {
					for(i = ini; i<fim; i++) {
						printf("%d ", fila[i]);
					}
					printf("\n");
				
				}
			}	
		}
	} while(opcao != 'F');


return 0;
}
