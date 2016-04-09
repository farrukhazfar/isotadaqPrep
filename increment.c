#include <stdio.h>
void pp(int datum) {
  printf("%d", datum);
}
int main(int argc, const char * argv[]) {
  int index,i2;
  for (index=0; index<10; index++) {
    i2 = index;
    printf("index: %d -- pp(index++): ", index);
    pp(i2++);
    i2 = index;
    printf(" -- pp(++index): ");
    pp(++i2);
    printf("\n");
  }
  return 0;
}
