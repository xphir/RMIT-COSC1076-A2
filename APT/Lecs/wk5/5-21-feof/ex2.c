#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char fname[] = "myfile";
	FILE *fp;
	int c, n = 0;
	
	fp = fopen(fname,"r");
	if (fp == NULL)
		fprintf(stderr, "Unable to open file %s\n",fname);
	else
	{
		while (1) {
			c = getc(fp);
			if (feof(fp))
				break;
			if (c == '$') 
				n++;
		}
		fclose(fp);
		printf("File contains %d $\n",n);
	}
	 
	return EXIT_SUCCESS;
	}
