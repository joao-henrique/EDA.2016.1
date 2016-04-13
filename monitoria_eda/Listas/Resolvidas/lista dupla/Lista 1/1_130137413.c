#include <stdio.h>
#include <math.h>

int main(){
	int i, num, compare, conf = 0;
	
	scanf("%d", &num);
	
	for(i=0; i<19; i++) {
		compare = 3*pow(2,i)-1;
		if(num == compare) conf = 1;
	}

	if(conf == 1)	
		printf("T\n");	
	else 	
		printf("N\n");	
return 0;
}
