#include <stdio.h>

void leia_palavra(char s[], int num) {
	int i, c;
	
		
	i = 0;	
	do {
		c = getchar();
		s[i] = c;
		i++;
	} while(i<num);
	s[i] = "\0";
}

void valida_palindromo(char s[], int num) {
	int i, j, valid;
	char suport[num];
	
	valid = num;
	i = 0;
	j = num-1;
	do {
		 if(s[i] == s[j]) valid--;
	} while(i < num);
	
	if(valid < 1) {
		i = 0;
		do {
			printf("%c", s[i]);
		} while(i < num);
		printf(" E UM PALINDROMO");
	} else {
		i = 0;
		do {
			printf("%c", s[i]);
		} while(i < num);
		printf(" NAO E UM PALINDROMO");
	}
}

int main(){

	int num;
	char palavra[50];	

	scanf("%d", &num);
	leia_palavra(palavra, num);	
	
	valida_palindromo(palavra, num);

return 0;
}
