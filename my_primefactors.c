#include <stdio.h>
#include <stdlib.h>
 
void prime_factors(int MAX, int *prime_array) {

    int allnums[MAX];
    int primes[MAX];
    int i,j,k;

    
      for(i=0;i<MAX;i++){
	primes[i]=-1;
      }
    
    

    /* Fill in all the numbers upto MAX */

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

    int prime_factor_counter=0;
    int product=1;

    /* now take the array of primes and divide the number by each prime found to determine how many times it can be divided */

    for(i=0;i<counter;i++) {
      product=primes[i];
      while(MAX%product==0){
	product*=primes[i];
	prime_array[prime_factor_counter]=primes[i];
	prime_factor_counter+=1;
      }
    }


    /* set all other entries to -999 (array is zie of the number itself) */

    for(i=counter; i<MAX;i++) {
      prime_array[i]=-999;
    }

    /* printing array from inside function from here */

    printf("Printing array from inside function...\n");

    for(i=0;i<prime_factor_counter;i++) {
      printf(" prime factor %d of %d = %d \n", i, MAX, prime_array[i]);
    }
}

 
int main(int argc, char *argv[]){
 

  int prime;
  
  printf("Please enter the number whose prime factors you want :\n");
  scanf("%d",&prime);

  /* first array dimension is where Eratosthenes algorithm will be used to sift the prime factors  */
  /* second array dimenstion is where we will mark the occurance of each factor...*/

  int *array = (int*)calloc(prime,sizeof(int));

  prime_factors(prime, array);


  int i =0;

  /* calling function from main, it seems that I do not get the correct array size  */

    printf(" \n");
    printf("Printing array from inside main...\n");
    printf("If this is not the same array that the function printed then the array has not been passed correctly \n");

      for(i=0;i<prime;i++) {
        if(array[i]>0)	printf(" prime factor %d of %d = %d \n", i, prime, array[i]);
    }
   
  return 0;
}
