#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void)
{
	FILE *fp;
	char fname[] = "myfile";
	int size = 0;
	
	fp = fopen(fname,"r");
	if (fp == NULL)
		fprintf(stderr, "Unable to open file %s\n",fname);
	else
	{
		fseek(fp,9,SEEK_END);
		size = ftell(fp);
		fclose(fp);
		printf("Size of myfile %d bytes\n",size);
	}
	 
	return EXIT_SUCCESS;
	}
