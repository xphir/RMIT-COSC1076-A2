#include <stdio.h>

int main(void)
{
  int p1 = 1, p2 = 2;

  #if DEBUG_LEVEL == 1
     printf("Debug: p1 = %d\n", p1);
  #else
  #if DEBUG_LEVEL == 2
     printf("Debug: p1 = %d p2 = %d\n", p1, p2);
  #endif 
  #endif

  return 0;
} 
