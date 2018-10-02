#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void)
{
	FILE *fp;
	char fname[] = "myfile";
	
	fp = fopen(fname,"w+");
	if (fp == NULL)
		fprintf(stderr, "Unable to open file %s\n",fname);
	else
	{
		fprintf(fp,"This is some data\nAnd some more\n");
		rewind(fp);
		fprintf(fp,"Overwrite");
		fclose(fp);
	}
	 
	return EXIT_SUCCESS;
	}
