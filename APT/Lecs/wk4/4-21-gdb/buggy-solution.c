/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* buggy.c
* A program with several deliberate errors. Use gdb to find them.
* Use commands: "r", "where", "br", "s", "n", "l", "c", and so on.
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   char myArray[10];
   int a = 10, b = 1, result, i;
   char s1[20] = "string";
   char* s2 = "another string";
   
   for (i = 0; i < 10; i++)
   {
      printf("%c ", myArray[i]);
   }
   printf("\n");
   
   result = a / b;
   printf("result = %d\n", result);
   
   strcpy(s1, s2);
   printf("%s\n", s2);
   
   return EXIT_SUCCESS;
}


