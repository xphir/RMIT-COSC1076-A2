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

Boolean invector_load(InVTable *invt, char *inputFile)
{
	Boolean result;
	InVTable localTable;
	FILE *stream;
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












int test(int argc, char **argv)
{
	FILE *fp;
	char line[MAX_LINE_LENGTH + NULL_SPACE];
	int numbers[MAX_NUMBERS];
	int numbersLength;
	char *token;
	int sum, i;

	if (argc != 2)
	{
		printf("Must pass a file name as a command line parameter. \n\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("File '%s' could not be opened for reading. \n\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (fgets(line, sizeof(line), fp) == NULL)
	{
		printf("Unable to read from file. \n\n");
		exit(EXIT_FAILURE);
	}
	fclose(fp);

	numbersLength = 0;
	token = strtok(line, ",");
	while (token != NULL)
	{
		char *tokenEndPtr;

		numbersLength++;
		if (numbersLength > MAX_NUMBERS)
		{
			printf("Too many tokens in file. \n\n");
			exit(EXIT_FAILURE);
		}

		numbers[numbersLength - 1] = strtol(token, &tokenEndPtr, 10);
		if (token == tokenEndPtr || *tokenEndPtr != '\0')
		{
			printf("Encountered corrupt data. \n\n");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, ",");
	}

	sum = 0;
	for (i = 0; i < numbersLength; i++)
	{
		sum += numbers[i];
	}

	fp = fopen(argv[1], "w");
	if (fp == NULL)
	{
		printf("File '%s' could not be opened for writing. \n\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < numbersLength; i++)
	{
		fprintf(fp, "%d,", numbers[i]);
	}
	fprintf(fp, "%d", sum);
	fclose(fp);

	printf("Finished. \n\n");

	return EXIT_SUCCESS;
}