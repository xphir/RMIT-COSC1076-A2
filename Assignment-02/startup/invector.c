/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "invector.h"

void invector_init(InVTable *invt)
{
	invt->tot = 0;
	invt->width = 0;
	return;
}

Boolean invector_load(InVTable *invt, char *inputFile)
{
	Boolean result;
	InVTable localTable;
	FILE *stream;
	char s[88];

	localTable = &invt;

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
				fwrite("Error: invector line too long\n", 1uLL, 0x1EuLL, stderr);
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
		if (*(_DWORD *)(localTable + 1000) > 0)
		{
			result = TRUE;
		}
		else
		{
			fwrite("Error: must have at least 1 invector\n", 1uLL, 0x25uLL, stderr);
			result = FALSE;
		}
	}
	else
	{
		fwrite("Failed to open invector file\n", 1uLL, 0x1DuLL, stderr);
		result = FALSE;
	}
	return result;
}