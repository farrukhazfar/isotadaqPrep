#include "print_lib.h"


/* print_lib.h will contain this function. Note that this function accesses the factorial */
/* functions without including the header here but will do in its header i.e print_lib.h*/

void calculate_seven_factorial() {
  printf("Iterative 7! :%d\n", iterative_factorial(7));
  printf("Recursive 7! :%d\n", recursive_factorial(7));
  printf("Iterative 7! counting upward :%d\n", iterative_factorial_hw(7));
  printf("Recursive 7! counting upward :%d\n", recursive_factorial_hw(7,1));
}
