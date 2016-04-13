#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int * leia_vetor() {
	int *n;
	
	n = (int *) malloc (sizeof(int));
	scanf("%d", &n);
	return n;
}

int main() {
	int *v[TAM];
	int i;
	
	for(i=0; i<TAM; i++) {
		printf("v[%d] = ", i);
		v[i] = leia_vetor();
	}
	
	for(i=0; i<TAM; i++)	printf(" %d ", v[i]);
	printf("\n");

return 0;
}
