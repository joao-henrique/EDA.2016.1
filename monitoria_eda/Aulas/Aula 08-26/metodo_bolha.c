#include <stdio.h>

/*int main() {

	int v[5] = {9,5,7,3,6};
	int aux, i, j;

	for(i=0; i<5; i++) printf("%d ", v[i]);
	printf("\n\n");

	for(i=0; i<5; i++) {
		for(j=i; j<5; j++) {
			if(v[i] < v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	for(i=0; i<5; i++) printf("%d ", v[i]);
	printf("\n\n");
return 0;
}
*/

int main() {
	int v[5] = {9,5,7,3,6};
	int aux, i, ls = 5;

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
	for(i=0; i<5; i++) printf("%d ", v[i]);
	printf("\n\n");
return 0;
}
