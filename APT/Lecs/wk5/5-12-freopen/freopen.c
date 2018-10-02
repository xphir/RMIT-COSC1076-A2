#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char fname[] = "myfile";
	FILE *fp;
	int num;
	
	fp = freopen(fname,"r",stdin);
	if (fp == NULL)
		fprintf(stderr, "Unable to open file %s\n",fname);
	else
	{
		fscanf(stdin,"%d",&num);
		printf("read %d\n",num);
		fclose(fp);
	}
	 
	return EXIT_SUCCESS;
	}
