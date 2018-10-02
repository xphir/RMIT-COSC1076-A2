#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char fname[] = "myfile";
	FILE *fp;
	
	fp = fopen(fname,"a+");
	if (fp == NULL)
		fprintf(stderr, "Unable to open file %s\n",fname);
	else
	{
		fprintf(fp,"456\n");
		fclose(fp);
	}
	 
	return EXIT_SUCCESS;
	}
