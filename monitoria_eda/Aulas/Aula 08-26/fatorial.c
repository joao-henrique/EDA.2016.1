#include <stdio.h>

int fatorial(int num) {
	if(num == 0) return 1;
	else return(num*fatorial(num-1));
}

int main() {

	int num, i, fat;

	printf("Informe o numero que deseja saber o fatorial: ");
	scanf("%d", &num);
/*	if(num == 0) fat = 1;
	for(i=num; i>0; i--) {
		if(i==num) fat = i;
		else fat *= i;
	} */

	fat = fatorial(num);

	printf("\nO fatorial de %d! é igual a: %d\n", num, fat);

return 0;
}
