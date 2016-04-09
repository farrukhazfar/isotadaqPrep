#include <stdio.h>


int sum_diff_mean (float a, float b, float *s, float* d, float* m) {

  if(a<0 || b<0) {printf("Error, one of the numbers is negative \n");return -999;}

  *s=a+b;
  *d=a-b;
  *m=(a+b)/2;

  return 1;

}


int main (int argc, const char * argv[] ){
  
  float a=5;
  float b=3;
  float sum, diff, mean;

  int i=sum_diff_mean(a,b,&sum,&diff,&mean);

  if(i>0){ 
  printf("Sum = %f difference = %f average = %f, \n",sum,diff,mean);
  }

  
  return 0;
}
