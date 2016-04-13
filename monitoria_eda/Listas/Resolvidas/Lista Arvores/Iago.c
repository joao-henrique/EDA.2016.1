#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void direitaDaString(char *mystring){
	FILE *fo = fopen("AlunosSai.txt", "w");
	int aux=0;
	do{
		if(isdigit(mystring[aux])== 0 && mystring[aux]!= 'ÿ'){
			putc(mystring[aux], fo);
		}
		aux++;
	}
	while(aux<255);
	fclose(fo);
}


int main(){

    FILE *fp = fopen("AlunosEnt.txt", "r");
	char mystring[255];
	int aux;
	for(aux=0; aux<255; aux++){
        mystring[aux] = getc(fp);
	}
	direitaDaString(mystring);
	fclose(fp);
	return 0;
}

