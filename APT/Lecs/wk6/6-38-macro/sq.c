/* to see the output from the preprocessor, you can type */
/* gcc -E sq.c      */
#include <stdio.h>

#define SQ(x)  (x) * (x)

int main()
{
  printf("Square of %i is %i \n", 5, SQ(5));
  printf("Square of %i is %i \n", 5-2, SQ(5-2));
  return 0;
}


