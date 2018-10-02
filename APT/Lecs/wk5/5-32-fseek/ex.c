#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void)
{
	FILE *fp;
	char fname[] = "myfile";
	
	fp = fopen(fname,"wb");
	if (fp == NULL)
		fprintf(stderr, "Unable to open file %s\n",fname);
	else
	{
		fputs("This is an apple",fp);
		fseek(fp,9,SEEK_SET);
		fputs(" same",fp);
		fclose(fp);
	}
	 
	return EXIT_SUCCESS;
	}
