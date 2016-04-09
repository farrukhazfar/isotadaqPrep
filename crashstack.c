#include <stdio.h>

int fun1(int x) {

  printf("Call number %d to fun1 \n",x+1);

  return fun1(x+1);

}

int main(int argc, const char * argv[]) {

  int test_stack=0;
  int return_argument;


    return_argument=fun1(test_stack);


  return 0;

}
