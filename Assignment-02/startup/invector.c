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

/* TODO */
int invector_get_num_invector(InVTable *invt)
{
	/* TODO */
	return 0;
}

/* TODO */
int invector_get_width(InVTable *invt)
{
	/* TODO */
	return 0;
}

/* TODO */
int invector_get_table_row(InVTable *invt, int a2)
{
	/* TODO */
	return 0;
}

/* TODO */
int invector_get_table_pos(InVTable *invt, int a2, int a3)
{
	/* TODO */
	return 0;
}

/* TODO */
Boolean invector_load(InVTable *invt, char *inputFile)
{
	Boolean result;
	InVTable * localTable;
	FILE *stream;
	char s[88];

	localTable = invt;

	/* Open inputFile for reading */
	stream = fopen(inputFile, "r");

	/* Try to open file */
	if (stream)
	{
		/* Read in inputFile */
		while (fgets(s, 82, stream))
		{
			/* Check line length */
			if (s[strlen(s) - 1] != 10)
			{
				/* line was to long */
				fwrite("Error: invector line too long\n", 1, 30, stderr);
				fclose(stream);
				return FALSE;
			}
			/* Read in inputFile */
			if (!invector_add(localTable, s))
			{
				fclose(stream);
				return FALSE;
			}
		}

		fclose(stream);
		if (localTable->tot > 0)
		{
			result = TRUE;
		}
		else
		{
			fwrite("Error: must have at least 1 invector\n", 1, 37, stderr);
			result = FALSE;
		}
	}
	else
	{
		fwrite("Failed to open invector file\n", 1, 29, stderr);
		result = FALSE;
	}
	return result;
}

Boolean invector_add(InVTable *invt, char *todo)
{
	return FALSE;
}