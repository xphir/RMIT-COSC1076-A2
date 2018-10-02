/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* malloc.c
* Example of malloc function.
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 60

char* makeString(); 

int main(void)
{
   char* string1 = "I am a fixed memory string";
   char* string2;
   char* string3;
   
	/* note (STR_SIZE + 1) works because char is 1 byte.
 	 * If doing a malloc for another data type, use sizeof
 	 * For example: to allocate memory for 4 doubles we would
 	 * give malloc the parameters: (4 * sizeof(double))
 	 */
   if ((string2 = malloc(STR_SIZE + 1)) == NULL)
   {
      printf("Unable to allocate %d bytes of memory.\n", STR_SIZE + 1);
      return EXIT_FAILURE;
   }
   strcpy(string2, "I am a dynamically allocated string");
   free(string2); 
   if ((string2 = malloc(STR_SIZE + 1)) == NULL)
   {
      printf("Unable to allocate %d bytes of memory.\n", STR_SIZE + 1);
      return EXIT_FAILURE;
   }
   strcpy(string2, "I am a dynamically allocated string");
  
   string3 = makeString();
 
   printf("string1: %s\n", string1);
   printf("string2: %s\n", string2);
   printf("string3: %s\n", string3);

   free(string2); 
   free(string3);

   return EXIT_SUCCESS;
}

/* Task: Create a function that returns dynamically allocated memory. */
char* makeString()
{
   char* string3;
   
   if ((string3 = malloc(STR_SIZE + 1)) == NULL)
   {
      printf("Unable to allocate %d bytes of memory.\n", STR_SIZE + 1);
      return NULL;
   }
   strcpy(string3, "I am a dynamically allocated string");

   return string3;
}

