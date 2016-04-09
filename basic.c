#include <stdio.h>
/* Define a variable to demonstrate use of ifdef (any value assigned works) */
#define RUN_IT_ALL 1

/* Define an int variable to assign an array size  */
#define ARRAY_SIZE 10340

/* Defining a struct */
struct georgebush {
  float testicles;
  float iq;
} georgebush_desc;


/* Above allows us to define structs as shown in program */


/* Defining a struct with typedef */
typedef struct georgebush_generic {
  float testicles;
  float iq;
} georgebush_desc_generic;


/* Above allows us to define structs as shown in program */
   


int main(int argc, const char * argv[]) {

#ifdef RUN_IT_ALL
  printf(" \n");
  printf("Printing a string with a character %c and a number %d \n", 'C', 420);
  printf("Hello, World!\n");
  printf(" \n");
  printf("********************* \n");
  printf("I will now divide %d by %d  \n",7,3);
  int a=7;
  int b=3;
  printf("Keeping my promise ?  7/3=%f  \n",a/b);
  printf("Keeping my promise ? 7./3=%f  \n",7./3);
  printf("Keeping my promise ? 7/3.=%f  \n",7/3.);
  printf("Keeping my promise ? 7/3=%f  \n",(float)a/b);
  printf(" \n");
  printf("********************* \n");


  printf(" \n");
  printf("********************* \n");


  char f='F';

  printf(" printing the ascii code of a character %d \n",f);

  printf(" and now printing its actual character value %c \n",f);

  printf(" \n");
  printf("********************* \n");

  int test_integer_array[ARRAY_SIZE];

  int i =0;

  for( i=0;i<10233;i++)
    {
      test_integer_array[i]=i;
      if(i<5)printf("testing integer array %d \n", test_integer_array[i]);
    }

  printf(" \n");
  printf("********************* \n");

  /* declaration and useage of struct...*/
  struct georgebush gwb;

  gwb.testicles=0;
  gwb.iq=-1000;

  printf("How many testicles does George Bush have and what is his iq ? Ans: %f %f \n", gwb.testicles, gwb.iq);

  /* declaration and useage of struct via typedef 9at top of program)...*/
  georgebush_desc_generic gwb_typedef;


  gwb_typedef.testicles=0;
  gwb_typedef.iq=-1000;

  printf("How many testicles does George Bush have and what is his iq ? Ans: %f %f \n", gwb_typedef.testicles, gwb_typedef.iq);



#else
  printf("Printing a string with a character %c and a number %d \n", 'C', 420);
#endif

  return 0;
}
