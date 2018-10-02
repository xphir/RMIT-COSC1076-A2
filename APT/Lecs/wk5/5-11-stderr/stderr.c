/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* stderr.c
* Example to facilitate the difference between stdout and stderr
* streams.
* Run program with:
* ( ./stderr > output.txt ) >& errors.txt
* or
* ./stderr > output.txt 2> errors.txt
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   fprintf(stdout,"Normal output\n");
   /* or just printf("Normal output\n"); */
   fprintf(stderr, "Error message\n");
 
   return EXIT_SUCCESS;
}
