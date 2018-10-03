/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "invector.h"

void invector_init(InVTable *invt)
{
	invt->tot = 0;
	invt->width = -1;
	return;
}

int invector_get_width(InVTable *invt)
{
	return invt->width;
}

int invector_get_num_invector(InVTable *invt)
{
	return invt->tot;
}

int * invector_get_table_row(InVTable *invt, int allele)
{
  return invt->table[allele];
}