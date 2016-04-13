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
			if(fim == 7)
				printf("Fila Cheia");
			else {
				fila[fim++] = num;
				for(i = ini; i<fim; i++)
					printf("%d ", fila[i]);
				printf("\n");
			}
		}
		else if(opcao == 'R') {
			if(ini == fim)
				printf("Fila Vazia");
			else {
				fila[ini++];
				for(i = ini; i<fim; i++)
						printf("%d ", fila[i]);
				printf("\n");
			}	
		}
			
	} while(opcao != 'F');


return 0;
}
