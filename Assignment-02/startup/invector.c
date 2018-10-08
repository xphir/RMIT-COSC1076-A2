/******************************************************************************
** Student name: 	Elliot Schot
** Student number: 	S3530160
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "invector.h"

/* Initialise the programs invtable */
void invector_init(InVTable *invt)
{
	invt->tot = 0;
	invt->width = -1;
	return;
}

/* Load in the input vector information */
Boolean invector_load(InVTable *invt, char *inputFile)
{

	Boolean result;
	char s[INV_LEN + EXTRA_SPACES];
	FILE *stream;
	/* read the input file */
	stream = fopen(inputFile, "r");
	if (stream)
	{	
		/* loop read the input file line by line with fgets */
		while (fgets(s, INV_LEN + EXTRA_SPACES, stream))
		{
			/* Check if the line "s" is the correct length */
			if (s[strlen(s) - 1] != 10)
			{
				fwrite("Error: invector line too long\n", 1, 30, stderr);
				fclose(stream);
				return FALSE;
			}
			/* Create the invector for this line */
			if (!invector_add(invt, s))
			{
				fclose(stream);
				return FALSE;
			}
		}
		fclose(stream);
		/* if tot-> 0 then invector has been loaded */
		if (invt->tot > 0)
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

/* Add a value to the invector table */
Boolean invector_add(InVTable *invt, char *inputString)
{
	char *endptr;
	char *dest;
	char *stringToken;
	int widthCount;
	int invtValue;
	char newLine[2] = "\n";
	widthCount = 0;
	/* Check if invt table is full */
	if (invt->tot > (INVT_MAX - 1))
	{
		fwrite("Error: invector table full\n", 1, 27, stderr);
		return FALSE;
	}

	dest = (char *)malloc(strlen(inputString) + 1);
	/* Filter out invalid invector values */
	if (dest == NULL)
	{
		fwrite("Unable to duplicate string\n", 1, 27, stderr);
		return FALSE;
	}
	if (!strncpy(dest, inputString, strlen(inputString) + 1))
	{
		fwrite("Unable to duplicate string\n", 1, 27, stderr);
		free(dest);
		return FALSE;
	}

	/* check the INV_DELIM1 value */
	stringToken = strtok(dest, INV_DELIM1);
	if (!stringToken)
	{
		fwrite("Error: invector string invalid\n", 1, 31, stderr);
		free(dest);
		return FALSE;
	}
	if (strncmp(stringToken, INV_LABEL, 12))
	{
		fwrite("Error: invector string invalid\n", 1, 31, stderr);
		free(dest);
		return FALSE;
	}

	/* check the INV_DELIM2 value */
	stringToken = strtok(NULL, INV_DELIM2);
	if (!stringToken)
	{
		fwrite("Error: invector string invalid\n", 1, 31, stderr);
		free(dest);
		return FALSE;
	}

	/* check the invtValue value is correct */
	invtValue = strtol(stringToken, &endptr, DECIMAL);
	if (*endptr)
	{
		fwrite("Error: invector string invalid\n", 1, 31, stderr);
		free(dest);
		return FALSE;
	}
	if (invt->tot != invtValue)
	{
		fwrite("Error: invector string invalid\n", 1, 31, stderr);
		free(dest);
		return FALSE;
	}
	while (TRUE)
	{
		/* Start working on the invector values */
		stringToken = strtok(NULL, INV_DELIM3);
		/* break the loop when it reaches the end of the invector eg INV_DELIM3 */
		if (stringToken == NULL)
		{
			break;
		}
		if (newLine[0] != *stringToken)
		{
			/* Check the invector width is correct */
			if (widthCount == INVT_WIDTH)
			{
				fwrite("Error: invector string invalid\n", 1, 31, stderr);
				free(dest);
				return FALSE;
			}
			/* Add the value from the file into the system */
			invt->table[invtValue][widthCount] = strtol(stringToken, &endptr, DECIMAL);
			widthCount++;
			if (*endptr)
			{
				fwrite("Error: invector string invalid\n", 1, 31, stderr);
				free(dest);
				return FALSE;
			}
		}
	}
	/* Check width count */
	if (widthCount == 0 )
	{
		fwrite("Error: invector string invalid\n", 1, 31, stderr);
		free(dest);
		return FALSE;
	}
	/* Add 1 to total invectors */
	invt->tot++;
	/* Check if invt->width has been used yet (-1 means initialised) */
	if (invt->width == -1)
	{
		invt->width = widthCount;
	}
	else if (invt->width != widthCount)
	{
		fwrite("Error: invector string invalid\n", 1, 31, stderr);
		free(dest);
		return FALSE;
	}
	free(dest);
	return TRUE;
}

/* Print the programs invtable */
void invector_print(InVTable *invt)
{
	int i, j;
	fprintf(stdout, "Invector Print:\n");
	for (i = 0; i < invt->tot; i++)
	{
		fprintf(stdout, "InputVector:%d(", i);
		for (j = 0; j < invt->width; j++)
		{
			fprintf(stdout, "%d", invt->table[i][j]);
			if (j < invt->width - 1)
			{
				fprintf(stdout, ",");
			}
		}
		fprintf(stdout, ")\n");
	}
}