#include <stdio.h>

int main()
{
int num=1;
char *cptr;

cptr = (char *)&num;

if (*cptr)
printf ("little endian\n");
else
printf ("big endian\n");

return 0;
}
