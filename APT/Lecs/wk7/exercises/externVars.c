/* Exercise 20 
 * this example is taken from page 241 of "A Book on C"
 */

#include <stdio.h>

int main(void)
{
   extern int a, b, c;  /* look for them elsewhere */

   printf("%3d%3d%3d\n", a, b, c);
   return 0;
}

int a = 1, b = 2, c = 3; 
