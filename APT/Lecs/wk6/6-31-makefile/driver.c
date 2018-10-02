/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* driver.c
* Example of makefiles.
* Citation: Slide 6-16 of PP2A/PT course notes.
****************************************************************************/

#include "driver.h"

int i = 7;

int main(void)
{
   /* Dummy function calls. */
   get();
   calcTotal();
   calcGrade();
   put();
   printf("i again: %d\n", i); 
   return EXIT_SUCCESS;
}
