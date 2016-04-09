#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

  /* rule which will be input by user */
  int rule = 0;

  /* seed position in array */
  int seed_position;

  /* eight bits for 2^0-> 2^7 */
  int mask =255;

  /* assorted counters */
  int i,j,k;

  /* Open file for text output */
  FILE *fp;

  fp=fopen("singlecells_evolution.txt","w");  

  /* Characters for text pattern */
  char alive='O';
  char dead=' ';

  /* row size for automata-> note that row-size-2 is divisible by 3 */
  int row_size =297;

  /* parent and child array */
  int parent[row_size], child[row_size];

  /* the number of generations to evolve according to this rule */
  int number_of_generations = 400;  

  /* All the possible combinations of previous generation neighbours */
  /* are the following numbers grouped in 3s... expressed as decimal numbers ... */
  /* 111 110 101 100 011 010 001 000 */
  /*  7   6   5   4   3   2   1   0 */
  /* ... and all packed into an array below .... in the same order that the rule_bits array (below) is packed/addressed */
  int all_possible_neighbours[8] = {0,1,2,3,4,5,6,7};

  printf("Please enter your rule for the cellular automa, this has to be a number between 0 and 255 (interesting ones are 18, 30, 110) \n");
  scanf("%d",&rule);
  printf("Please enter the position of the first cell on the array this has to be a number between 1 and 299 (a good place to start is 147) \n");
  scanf("%d",&seed_position);

  /* Now print out the bit pattern to show the reader what this looks like in Binary */

  int bits =0;
  int rule_bits[8];

  /*  

  fprintf(fp,"Your rule (with the number you entered on the second line in binary is : \n") ;
  fprintf(fp," 111  110  101  100  011  010  001  000 \n");

  */

  for(i=0;i<8;i++) {
    bits= ((mask & rule) & (int)pow(2,i))>>i;
    rule_bits[i]=bits;
}

  /* print out the bits in reverse order to match the pattern */
  /*
  for(i=0;i<8;i++) {
    fprintf(fp,"  %d  ", rule_bits[7-i]);
  }
  */

  fprintf(fp,"\n");

  for(k=0;k<row_size;k++){
    parent[k]=0;
    child[k]=0;
  }

  /*  
  fprintf(fp," ************** Here come the single cells ****************** \n");
  */

  /* seed with one initial cell alive */
  parent[seed_position]=1;

  for(i=0;i<row_size;i++){
    if(parent[i]==0) fprintf(fp,"%c",dead);
    if(parent[i]==1) fprintf(fp,"%c",alive);
  }
       fprintf(fp,"\n");


       /* loop over number of generations...*/
  for (i=0;i<number_of_generations; i++) {
    /* nested loop over each row, implementing the rule */
    for (j=1;j<row_size-1;j++) {
      child[j]=rule_bits[parent[j+1]*4+parent[j]*2+parent[j-1]*1];
      if(child[j]==1)fprintf(fp,"%c", alive);
      if(child[j]==0)fprintf(fp,"%c", dead);            
    }

    fprintf(fp,"\n");
      
      /* Now calling previous child the parent of the next */
    for (j=0;j<row_size-1;j++) {
      parent[j]=child[j];
    }

  }

   


    return 0;
}
