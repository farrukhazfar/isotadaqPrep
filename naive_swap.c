#include <stdio.h>

void swap( int as, int bs) {

  printf("Function swap input %d %d \n",as, bs);

  int tmp;
  /* swap variables */
  tmp=as;
  as=bs;
  bs=tmp;
  printf("Function swap after swapping %d %d \n",as, bs);
  
}


void swap_with_pointers ( int* as, int* bs) {

  int *tmp;
  
  tmp = bs;
  bs=as;
  as=tmp;

  printf("Function swap after swapping %d %d \n",*as, *bs);
}


int main (int argc, const char * argv[] ){
  
  int a=5;
  int b=3;

  printf("Input to swap function a=%d b=%d \n", a, b);
  swap(a,b);
  printf("I now print a=%d and b=%d to demonstrate the obvious \n",a,b);

  printf("Input to swap_with_pointers function a=%d b=%d \n",a,b);
  swap_with_pointers(&a, &b);
  printf("Did the trick with pointers work ? a= %d b=%d \n",a, b);



  return 0;
}
