#include <stdio.h>

int main() {
	int v[5] = {9,5,7,3,6};
	int aux, i, ls = 5, li = 0;
	int num, k;

	while(ls > 1) {
		i = 0;
		while(i < ls) {
			if(v[i] < v[i+1]) {
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		i++;
		}
	ls--;
	}

	printf("Numero a procurar posicao: ");
	scanf("%d", &num);
	ls = 5;
	do {
		i = (ls + li) / 2;
		//printf("\ni = %d, ls = %d, li = %d\n", i,ls,li);
		if(v[i] == num) {
			printf("\n esta na posicao %d\n: ", i);
		}
		if(v[i] < num) ls = i-1;
		else li = i+1;
	} while(i != k && ls > li);

	for(i=0; i<5; i++) printf("%d ", v[i]);
	printf("\n\n");
return 0;
}
