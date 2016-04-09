#include <stdio.h>
#include <stdlib.h>
 
#define MAX 15
 
int main(int argc, char *argv[]){
 
    int allnums[MAX];
    int primes[MAX];
    int i,j,k;

    for(i=0;i<MAX;i++){
      primes[i]=-1;
    }

    /* fill in the numbers from 0-121 first */

    for(i=0;i<MAX;i++) {
      allnums[i]=i+1;
    }

    /* Now find all primes using the sieve of the Big E-man */

    int increment_by_me;
    int marked=0;

    

    for(i=1;i<MAX;i++) {
      if(allnums[i]>1){
	increment_by_me=allnums[i];
	for(j=i;j<MAX;j+=increment_by_me) {
	  if(j>i)allnums[j]=-1;
	}
      }
    }
 
    int counter=0;

    for(k=0;k<MAX;k++){

      if(allnums[k]>1){primes[counter]=allnums[k];counter+=1;}

    }

    printf("counter %d \n", counter);

    for(i=0;i<counter;i++){
      printf(" %d \n ", primes[i]);
    }
   
      return 0;
}
