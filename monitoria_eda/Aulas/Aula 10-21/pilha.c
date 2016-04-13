#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bemformada(char s[]) {
	char *pilha;
	int n, i, t;
	n = strlen(s);
	pilha = malloc(n*sizeof(char));
	t = 0;
	for(i=0; s[i]!='\0'; i++) {
		switch(s[i]) {
			case ')':
				if(t!=0 && pilha[t-1]=='(')
					t--;
				else 
					return 0;
				break;
			
			case ']':
				if(t!=0 && pilha[t-1]=='[')
					t--;
				else
					return 0;
				break;
				
			default:
				pilha[t++]=s[i];
		}
	}
	return t==0;
}

int main() {
	char s[9] = {'(', '[', '(', '(', ')', ')', ']', ')', '\0'};
	
	if(bemformada(s))
		printf("Verdadeiro\n");
	else
		printf("Falso\n");

return 0;
}
