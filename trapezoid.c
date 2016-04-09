#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50000

float function(float x) {
  return sqrt(4.-x*x);
}


float integrate(float func[], int len, float low, float high) {

  int index=0;
  float result=0;
 

  for(index=1;index<len;index++) {
    result+=(high-low)/(len)*func[index];
  }   

  result=result+func[0]/2.+func[len]/2.;
  return result;

}


float integrate_mc(int seed1, int seed2, float xlo, float xhi, float ylo, float yhi, int iter) {

  int i=0;
  int counter =0;
  float x,y;
  
  for(i=0;i<iter;i++) {
    x = (float)rand()/(float)RAND_MAX*(xhi-xlo)+xlo;
    y = (float)rand()/(float)RAND_MAX*(yhi-ylo)+ylo;

    if(function(x)>y)counter++;
    
  }
  
  return ((float)counter)/((float)iter)*(xhi-xlo)*(yhi-ylo);
}

int main(int argc, const char * argv[] ) {

  int i=0;
  int index=0;
  int LEN;

  float low=-2.0;
  float hi =2.0;

  float func[MAXLEN];

  printf("Please enter the number of bins you want to split the range into \n");
  scanf("%d",&LEN);

  /* create interval size */
  float interval=(hi-low)/LEN;

  for(index=0;index<LEN+1;index++) {

    func[index]=function(low+index*interval);

  }



  /* Monte Carlo integration using ranf */


  float mcint=  integrate_mc(76767457, 3435435, -2., 2, 0., 2., LEN);
  srand(32443334);  
 
  printf("The integral of sqrt(4-x^2)/2  between -2. and 2.should be pi= %f \n",2*3.14159265);
  printf("The integral of sqrt(4-x^2)/2 between -2. and 2. using trapezoid approximation is %f \n",integrate(func,LEN,low,hi));
  printf("The integral of sqrt(4-x^2)/2 between -2. and 2. using Monte-Carlo integration with %d iterations is %f \n",LEN, mcint);


 return 0;
}
