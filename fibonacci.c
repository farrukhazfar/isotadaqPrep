#include <stdio.h>


int recursive_fibonacci(int num) {
  if(num==0) return 0;
  if(num==1) return 1;
  if(num<0){printf("Warning: you have entered a negative number returning -1"); return -1;}
  return recursive_fibonacci(num-1)+recursive_fibonacci(num-2);

}




int iterative_fibonacci(int num) {

  /* result is the sum of F0 and F1 and equals F2 */
  int i, result=0;

  if(num<0){printf("function iterative fibonacci: Warning, N is less thanzero, Fibonacci Number undefined \n");}
  if(num<=0)return 0;
  if(num==1)return 1;

  int f0=0;
  int f1=1;

  /* initialize fminus1 and fminus2 to 0 and 1, (f0 and f1)...*/
  int fminus1=1;
  int fminus2=0;

  for(i=0;i<num-1;i++){
    result = fminus1+fminus2;
    fminus2=fminus1;
    fminus1=result;
  
}
  return result;
}

int main(int argc, const char * argv[]) {

  int i;
  for(i=0; i<=15;i++) {

    printf("iterative fibonacci numbers = F%d %d \n",i, iterative_fibonacci(i)); 
    printf("recursive fibonacci numbers = F%d %d \n",i, recursive_fibonacci(i)); 
    
  }

  return 0;
}
