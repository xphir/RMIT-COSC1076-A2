#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char fname[] = "myfile";
	FILE *fp;
	
	fp = fopen(fname,"r");
	if (fp == NULL)
		fprintf(stderr, "Unable to open file %s\n",fname);
	else
		fclose(fp);
	 
	return EXIT_SUCCESS;
	}
