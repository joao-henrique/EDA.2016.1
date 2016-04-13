#include <stdio.h>

int main() {

	int i;
	int primeira;
	int total_imp;
	int test = 0;

	//scanf("%d %d", &primeira, &total_imp);
	scanf("%d", &primeira);
	scanf("%d", &total_imp);	
	test = primeira;
	for(i=1; i<total_imp; i++) test++;
	
	if(primeira%2 == 0 && test%2 == 0) printf("%d\n", test);
	else if(primeira%2 == 0 && test%2 != 0) printf("0\n");
	else if(primeira%2 != 0 && test%2 != 0)	printf("%d\n", test);
	else if(primeira%2 != 0 && test%2 == 0) printf("0\n");

return 0;
}
