/****************************************************************************
* ptr.c
* Pointer arithmetic example.
* Adapted from: Steven Burrows sdb@cs.rmit.edu.au
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   float table[4] = {2.24, 4.24, 3.24, -2.1};
   float *fp, *start, *end;

   float sum = 0.0;
   int  j;

   fp = table;
   
   for (j = 0; j < 4; j++, fp++)
   {
	   sum += *fp; 
      /* Normally we might just do: sum += table[j]; */
   }

   printf("The sum is: %.2f\n", sum);

   fp = table;
   sum = 0.0;

   for (fp = table; fp < table + 4; fp++)
   {
	   sum += *fp;
   }

   printf("The sum is: %.2f\n", sum);
   
   start = table;
   end = table + 4;
   sum = 0.0;

   for ( ; start < end; start++)
   {
	   sum += *start;
   }

   printf("The sum is: %.2f\n", sum);
   
   fp = table;
   sum = 0.0;

   for (j = 0; j < 4; j++)
   {
      sum += fp[j];
   }

   printf("The sum is: %.2f\n", sum);

   fp = table;
   sum = 0.0;
   
   for (j = 0; j < 4; j++)
   {
      sum += *(fp + j);
   }

   printf("The sum is: %.2f\n", sum);
   
   sum = 0.0;

   for (j = 0; j < 4; j++)
   {
      sum += table[j];
   }
   printf("The sum is: %.2f\n", sum);

   sum = 0.0;
   for (j = 0; j < 4; j++)
   {
      sum += *(table + j);
   }

   printf("The sum is: %.2f\n", sum);
   
   return EXIT_SUCCESS;
}
