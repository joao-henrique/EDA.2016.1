
#include <stdio.h>
#include <math.h>

int cal_thabit(int k){
  int calc = 3* (pow(2,k))-1;
  return calc;
}


int main(int argc, char const *argv[]) {

  int k,i=0;
  printf("Informe um numero:");
  scanf("%d", &k);


  while(k != i ){

      printf("%d\n", cal_thabit(i) );

    i++;

  }


  return 0;
}
