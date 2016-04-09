#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{


  int total_mask=0x01;
  int hadaf;
  int divided;

  printf("Please enter the number whose prime factors you want \n");
  scanf("%d",&hadaf);
  int howmanyby2=0;
  int j=0;
  int k=0;
  
  divided = hadaf;
  int check2 = hadaf;

  /* divide the input by two as long as it remains even */
  while ((total_mask & hadaf)==0 && divided>=1 ) { 
    divided = divided/2; howmanyby2++;
  }
  
  
    printf("Your number was a multiple of 2 \n");
    printf("The single prime factor is simply 2 raised to the power %d \n",howmanyby2-1);
   
    return 0;
}
