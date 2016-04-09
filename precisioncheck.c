#include <stdio.h>
#include <math.h>


int fun0(int x) {

  x=2*x;
  return x;

}



int main(int argc, const char * argv[]) {

  int i;

  i =1;

  while ( i > 0) {

    i=fun0(i);

  }


  float f = i;
   
  if(i<0) printf(" precision is %f bits \n",log(-f)/log(2.)+1);
  
  return 0;
}
