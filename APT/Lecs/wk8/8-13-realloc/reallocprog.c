/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* realloc.c
* Example of realloc function.
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define INC 3

int main(void)
{
   int *array = NULL, *temp, avail = 0, used = 0, num, i;

   printf("Enter some integers (one per line, CTRL-D to finish):\n");
   
   while (scanf("%d", &num) == 1)
   {
      if (used == avail)
      {
         avail += INC;
         
         printf("*** Array memory is reallocated with realloc()!\n");
         if ((temp = realloc(array, avail * sizeof(int))) == NULL)
         { 
            printf("Could not reallocate %d bytes of memory.\n", 
                     avail * sizeof(int));  
            break;
         }
         else
         {
            array = temp;
         }
      }
      array[used++] = num;
   }
   
   printf("\nYou entered:\n");
   for (i = 0; i < used; i++)
   {
      printf("%d ", array[i]);
   }
   printf("\n");
   
	return EXIT_SUCCESS;
}

