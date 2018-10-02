/* to see the output from the preprocessor, you can type */
/* gcc -E sq.c      */
#include <stdio.h>

#define SQ(x)  ((x) * (x))

int main()
{
  printf("Square of %d is %d \n", 5, SQ(5));
  printf("sq(%d) / sq(%d) is %d \n", (6-2),(4-2), SQ(6-2)/SQ(4-2));
  return 0;
}


