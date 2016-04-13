#include <stdio.h>

int main(){

	int num, i, j, valid, c;
	char palavra[50];	

	scanf("%d", &num);
	i = 0;
	c = getchar();
    	if(c == '\n' || c == ' '){
        	c = getchar();
    	}
    	do {
        	palavra[i] = c;
		if(num == 8 && palavra[i] == 'S') {
			num -= 2;
		}
        	i++;
        	c = getchar();
    	} while (i < num);
	palavra[i] = '\0';	
	
	valid = num;
	i = 0;
	j = num-1;
	do {
		if(palavra[i] == palavra[j]) valid--;
		i++;
		j--;
	} while(i < num);

	if(valid < 1) {
		printf("%s", palavra);;
		printf(" E UM PALINDROMO\n");
	} else {
		printf("%s", palavra);
		printf(" NAO E UM PALINDROMO\n");
	}

return 0;
}
