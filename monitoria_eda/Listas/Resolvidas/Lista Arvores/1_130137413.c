#include <stdio.h>
#include <stdlib.h>

typedef struct _Arv {
	int info;
	struct _Arv *esq;
	struct _Arv *dir;
} Arv;

Arv* inserir(Arv *head, int num2) {
	Arv *aux = malloc(sizeof(Arv));
	Arv = aux2;
	
	aux2 = head;
	aux -> info = num2;
	aux -> esq = aux -> dir = NULL;
	if(head == NULL)
		return head;
	for() {
		if(aux2 -> esq == NULL) {
			aux2 -> esq = aux;
			return head;
		}
		else if(aux2 -> dir == NULL) {
			aux2 -> dir = aux;
			return head;
		}
		else
			aux2 =
	}
	return head;
}

int main(){
	int num, num2, i;
	Arv *head;
	
	head = NULL;
	
	scanf("%d", &num);
	for(i=0; i<num; i++) {
		scanf("%d", &num2)
		head = inserir(head, num2);
	}
return 0;
}
