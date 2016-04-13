#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *infixaposfixa(char inf[]) {
	char *posf;
	char *pilha;
	int t, n, i, j;
	
	n = strlen(inf);
	posf = malloc(n*sizeof(char));
	pilha = malloc(n*sizeof(char));
	t = 0;
	pi[t++] = inf[0];
	
	for(j=0,i=1; inf[i]!='\0';i++) {
		switch(inf[i]) {
			case '(':
				pilha[t++] = inf[i];
				break;
				
			case ')':
				while(t) {
					x = pilha[--t];
					if(x=='(')
						break;
					posf[j++] = x;
				}
				break;
				
			case '+':
			case '-':
				while(1) {
					x = pilha[t-1];
					if(x=='(')
						break;
					t--;
					posf[j++] = x;
				}
				pilha[t++] = inf[i];
				break;
				
			case '*':			
			case '/':
				while(1) {
					x = pilha[t-1];
					if(x == '(' || x == '+' || x == '-')
						break;
					t--;
					posf[j++] = x;
				}
				pilha[t++] = info[i];
				break;
				
			default:
				posf[j++] = inf[i];
				
		}
	}
	free(pilha);
	posf[j]='\0';
	return posf;
}
