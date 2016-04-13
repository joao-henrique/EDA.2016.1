#include<stdio.h>
#include<stdlib.h>

typedef struct Pilha {
	int i;
	int j;
	int ia;
	int ja;
	struct Pilha *prox;
	struct Pilha *ant;
} pilha;

pilha *empilhar(pilha *p, int i, int j, int iant, int jant) {
	if(i == iant && j == jant)
		return p;
	pilha *q;
	q = (pilha*) malloc(sizeof(pilha));
	q -> i = i;
	q -> j = j;
	q -> ia = iant;
	q -> ja = jant;
	q -> prox = NULL;
	q -> ant = NULL;
	if(p == NULL)
		return q;
	q -> prox = p -> prox;
	p -> prox = q;
	q -> ant = p;
	return p;
}

pilha *desempilhar(pilha *p) {
	pilha *aux = p;
	if(p -> prox == NULL) {
		p -> i = p -> j = 0;
		return p;
	}
	else {
		p = p -> prox;                     
		p -> ant = NULL;                //   p -> prox -> ant == p...  Essa linha apagou 'p' do meio da pilha
		free(aux);
		return p;
	}
}

int acharsaida(int labirinto[][12]) {
	int i = 1, j = 1, iant = 0, jant = 0, c = 0;
	pilha *p = NULL;
	int verifica = 0;
	int parada = 0;
	empilhar(p, 1, 1, 0, 0);
	labirinto[1][1] = 1;
	
	do {
		c++;
		if(labirinto[i+1][j] == 0) {
			labirinto[i+1][j] = c;               /*    a lógica pra verificar a posição anterior está errada.           */
			p = empilhar(p, i+1, j, iant, jant);           /*    está verificando se a posição não foi alterada, ao invés de      */
		}
		else                                     /*    verificar se foi para a posição anterior...                      */
			verifica++;
			
		if(labirinto[i][j+1] == 0) {
			labirinto[i][j+1] = c;
			p = empilhar(p, i, j+1, iant, jant);
		}
		else
			verifica++;
			
		if(labirinto[i-1][j] == 0) {
			labirinto[i-1][j] = c;
			p = empilhar(p, i-1, j, iant, jant);
		}
		else
			verifica++;
			
		if(labirinto[i][j-1] == 0) {
			labirinto[i][j-1] = c;
			p = empilhar(p, i, j-1, iant, jant);
		}
		else
			verifica++;
			
		if(verifica == 4)
			return 0;
		
		printf("%d %d %p %d\n", i, j, p, parada);
		p = desempilhar(p);
		
		i = p -> i;
		j = p -> j;
		iant = p -> ia;
		jant = p -> ja;
		parada++;
	} while(i != 10 && i != 0 && parada != 100);
	if(i==10 && parada != 99)
		return 1;
	else
		return 0;
}

void cria(int L[12][12]) {
	int i, j;
	for(i=0; i<12; i++) {
		L[i][0] = 1;
		L[i][11] = 1;
	}
	for(j=0; j<12; j++) {
		L[0][j] = 1;
		L[11][j] = 1;
	}
	
	for(i=1; i<11; i++) {
		for(j=1; j<11; j++) {
			if( rand()%3==0 )
				L[i][j] = 1;
			else
				L[i][j] = 0;
		L[1][1] = 0;
		L[10][10] = 0;
		}
	}
}


int main() {
	int labirinto[12][12], i, j;

/*	for(i=0; i<12; i++) {
		for(j=0; j<12; j++) {
			labirinto[i][j] = 0;
		}
	}

	for(i=0; i<12; i++) {
		labirinto[0][i] = 1;
		labirinto[11][i] = 1;
		labirinto[i][0] = 1;
		labirinto[i][11] = 1;
	}
	*/
	
	cria(labirinto);
	
	if(acharsaida(labirinto))
		printf("\n Com Saida \n");
	else
		printf("\n Sem Saida \n");
		
	for(i=0; i<12; i++) {
		for(j=0; j<12; j++) {
			if(labirinto[i][j] == 1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
	

return 0;
}

/*                          {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
							 {-1,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1},
							 {-1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
							 {-1,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1},
							 {-1, -1, -1,  0,  0,  0, -1, -1, -1, -1, -1, -1},
							 {-1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1},
							 {-1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1},
							 {-1, -1, -1,  0,  0,  0, -1, -1, -1, -1, -1, -1},
							 {-1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1},
							 {-1, -1, -1,  0,  0,  0,  0,  0, -1, -1, -1, -1},
							 {-1, -1, -1, -1, -1, -1, -1,  0,  0,  0,  0, -1},
							 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
*/
