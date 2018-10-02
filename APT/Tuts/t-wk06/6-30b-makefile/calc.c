/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* calc.c
* Example of makefiles.
****************************************************************************/
#include <stdio.h>

#include "calc.h"

void calcTotal()
{
	printf("This is function calcTotal()\n");
#ifdef DEBUG
	printf("DEBUG lives!\n");
#endif
}

void calcGrade()
{
	printf("This is function calcGrade()\n");
}
