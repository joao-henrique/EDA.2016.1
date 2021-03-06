#include <stdio.h>
#include <stdlib.h>

int *distancias(int A[][6], int c) {
	int *d, j;
	int fila[6], ini, fim;
	int i, di;
	
	d = malloc(6*sizeof(int));
	for(j=0; j<6; j++) {
		d[j] = 6;
	}
	d[c] = 0;
	ini = 0;
	fim = 0;
	fila[fim++] = c;
	
	do {
		i = fila[ini++];
		di = d[i];
		for(j=0; j<6; j++) {
			if(A[i][j] == 1 && d[j] == 6) {
				d[j] = di+1;
				fila[fim++] = j;
			}
		}
	} while(ini!=fim);
	return d;
}

int main() {
	int *d, c, i;
	int A[6][6] = {{0, 0, 0, 0, 0, 0},
			  	   {1, 0, 0, 0, 0, 0},
			       {0, 1, 0, 0, 1, 0},
			       {0, 0, 1, 0, 1, 0},
			       {1, 0, 0, 0, 0, 0},
			       {0, 1, 0, 0, 0, 0}};
	scanf("%d", &c); 
	d = distancias(A, c);
	for(i=0; i<6; i++)
		printf("%d ", d[i]);


return 0;
}
