#include <stdio.h>
#include <math.h>


/* checking the endian ness of this computer */

/* First write down 2^31 */



int main(int argc, const char * argv[]) {

  /* What am I doing here ? Well I know this machine has 32 bit precision. 0xffffffff with f=1111 (15 in decimal) */
  /* Now I can do the and operation with a specific MAXINT (which I took out of the excercise). Note I am masking */
  /* a byte at a time (8 bits). I am also shifting this */

  int MAXINT=1937425042;

  printf("Breaking up 1937425042 into bytes: first byte from right %d \n",(0x000000ff&MAXINT));

  printf("Breaking up 1937425042 into bytes: second byte from right %d \n",(0x0000ff00&MAXINT)>>8);

  printf("Breaking up 1937425042 into bytes: third byte from right %d \n",(0x00ff0000&MAXINT)>>16);

  printf("Breaking up 1937425042 into bytes: fourth byte from right %d \n",(0xff000000&MAXINT)>>24);

  /* Now the bits have to be shifted down, by 8, 16, and 24 */

  int first = (0x000000ff&MAXINT);
  int second = (0x0000ff00&MAXINT)>>8;
  int third = (0x00ff0000&MAXINT)>>16;
  int fourth = (0xff000000&MAXINT)>>24;

  /* Now we check this to see what the endian ness is. For this we have to the sum of each down-shifted number */
  /* in the two possible orders and see which one matches MAXINT */

  int bigend = fourth*pow(2,24)+third*pow(2,16)+second*pow(2,8)+first;

  int littlend = first*pow(2,24)+second*pow(2,16)+third*pow(2,8)+fourth;


  if(bigend==MAXINT)printf("This is a big endian machine \n"); 

  if(littlend==MAXINT)printf("This is a little endian machine \n"); 


  return 0;
}
