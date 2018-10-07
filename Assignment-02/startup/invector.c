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

int *invector_get_table_row(InVTable *invt, int allele)
{
	return invt->table[allele];
}

Boolean invector_load(InVTable *invt, char *inputFile)
{
	Boolean result;
	InVTable *localinvt;
	char s[88];
	FILE *stream;

	localinvt = invt;
	stream = fopen(inputFile, "r");
	if (stream)
	{
		while (fgets(s, 82, stream))
		{
			if (s[strlen(s) - 1] != 10)
			{
				fwrite("Error: invector line too long\n", 1, 30, stderr);
				fclose(stream);
				return FALSE;
			}
			if (!invector_add(localinvt, s))
			{
				fclose(stream);
				return FALSE;
			}
		}
		fclose(stream);
		if (localinvt->tot > 0)
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
	stringToken = strtok(NULL, INV_DELIM2);
	if (!stringToken)
	{
		fwrite("Error: invector string invalid\n", 1, 31, stderr);
		free(dest);
		return FALSE;
	}
	invtValue = strtol(stringToken, &endptr, 10);
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
		stringToken = strtok(NULL, INV_DELIM3);
		if (stringToken == NULL)
		{
			break;
		}
		if (newLine[0] != *stringToken)
		{
			if (widthCount == INVT_WIDTH)
			{
				fwrite("Error: invector string invalid\n", 1, 31, stderr);
				free(dest);
				return FALSE;
			}
			invt->table[invtValue][widthCount] = strtol(stringToken, &endptr, 10);
			widthCount++;
			if (*endptr)
			{
				fwrite("Error: invector string invalid\n", 1, 31, stderr);
				free(dest);
				return FALSE;
			}
		}
	}
	if (!widthCount)
	{
		fwrite("Error: invector string invalid\n", 1, 31, stderr);
		free(dest);
		return FALSE;
	}
	invt->tot++;
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

int invector_get_table_pos(InVTable *invt, int a2, int a3)
{
	return invt->table[a3][a2];
}