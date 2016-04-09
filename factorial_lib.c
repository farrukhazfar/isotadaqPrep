#include "factorial_lib.h"

int recursive_factorial(int num) {
  if(num==1) return 1;
  return num * recursive_factorial(num-1);
}

int iterative_factorial(int num) {
  int i, result=1;
  for(i=num; i>1; i--){result *=i;}
  return result;
}

/* excercise 1 implementation of above two functions counting upward */


int recursive_factorial_hw(int num, int where) {
  if(where>num)return 1;
  if(num==1 || num==0) return 1;
  return where*recursive_factorial_hw(num,where+1);
}

int iterative_factorial_hw(int num) {
  int result,i;
  if(num==1 ||num==0)return 1;

  result=1;
  for(i=1; i<=num;i++){
    result *=i;}
    return result;
}

