#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void)
{
	FILE *fp;
	char fname[] = "myfile";
	char str[SIZE + 1];
	
	fp = fopen(fname,"r");
	if (fp == NULL)
		fprintf(stderr, "Unable to open file %s\n",fname);
	else
	{
		while (fgets(str,sizeof(str),fp) != NULL) {
			printf("read :%s:\n",str);
		}
		fclose(fp);
	}
	 
	return EXIT_SUCCESS;
	}
