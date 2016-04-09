#include <stdio.h>
#define LEN 20

int sum (int ints[], int len) {

  int index=0;
  int result=0;

  for(index=0;index<len;index++) {
    result +=ints[index];
  }   


  return result;


}


int main(int argc, const char * argv[] ) {

  int i=0;
  int array[LEN];

  for(i=0; i<LEN; i++) {
    array[i]=i;
  }

printf("The sum of the first %d integers including 0 is %d \n",i,sum(array,LEN));

 return 0;
}
