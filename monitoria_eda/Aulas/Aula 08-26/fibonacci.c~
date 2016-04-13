#include <stdio.h>
#include <stdlib.h>

void fibonacci(int vet[], int lims, int a, int b, int c) {
		
	if (c != lims) { // Critério de parada definido no main.
		if(c <= 1) {      // Condição para os dois primeiros números de fibonacci 0 e 1.
			vet[c] = c; //  Os valores de a e b, continuam os mesmos enquanto c <= 1.
			c ++;
			fibonacci(vet,lims, a, b, c);
		}	
			else {  // A partir daqui o código continua a contagem de fibonacci a partir de a e b.
				vet[c] = a + b;
				a = b;
				b = vet[c];
				c++;
				fibonacci(vet, lims, a, b, c);
			}
	}
}

int main() {

	int i, lims;
	int *vet;
	int a = 0, b = 1, c = 0;

	printf("Informe o limite de caracteres que deseja \nque a sequencia de fibonacci seja exibida: ");
	scanf("%d", &lims);

	vet = (int*) malloc(lims*sizeof(int));

	fibonacci(vet, lims, a, b, c);
	
	for(i = 0; i<lims; i++) {
		printf("%ld ", vet[i]);
	}
	printf("\n");
	
	free(vet);

return 0;
}
